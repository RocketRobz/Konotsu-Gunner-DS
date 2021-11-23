#include "sound.h"

#include "soundbank.h"
#include "soundbank_bin.h"

#include "streamingaudio.h"
#include "string.h"
#include "tonccpy.h"
#include <algorithm>


extern volatile s16 fade_counter;
extern volatile bool fade_out;

extern volatile s16* play_stream_buf;
extern volatile s16* fill_stream_buf;

// Number of samples filled into the fill buffer so far.
extern volatile s32 filled_samples;

extern volatile bool fill_requested;
extern volatile s32 samples_left_until_next_fill;
extern volatile s32 streaming_buf_ptr;

#define SAMPLES_USED (STREAMING_BUF_LENGTH - samples_left)
#define REFILL_THRESHOLD STREAMING_BUF_LENGTH >> 2

#ifdef SOUND_DEBUG
extern char debug_buf[256];
#endif

extern volatile u32 sample_delay_count;

SoundControl::SoundControl()
	: stream_is_playing(false), stream_source(NULL)
 {

	mmInitDefaultMem((mm_addr)soundbank_bin);

	mmLoadEffect( SFX_GUNSHT );
	mmLoadEffect( SFX_AMMOOUT );
	mmLoadEffect( SFX_HURT );
	mmLoadEffect( SFX_PLYRJMP8 );
	mmLoadEffect( SFX_GUNEMPTY );

	snd_gunsht = {
		{ SFX_GUNSHT } ,			// id
		(int)(1.0f * (1<<10)),	// rate
		0,		// handle
		255,	// volume
		128,	// panning
	};

	snd_ammoout = {
		{ SFX_AMMOOUT } ,			// id
		(int)(1.0f * (1<<10)),	// rate
		0,		// handle
		255,	// volume
		128,	// panning
	};

	snd_hurt = {
		{ SFX_HURT } ,			// id
		(int)(1.0f * (1<<10)),	// rate
		0,		// handle
		255,	// volume
		128,	// panning
	};

	snd_jump = {
		{ SFX_PLYRJMP8 } ,			// id
		(int)(1.0f * (1<<10)),	// rate
		0,		// handle
		255,	// volume
		128,	// panning
	};

	snd_gunempty = {
		{ SFX_GUNEMPTY } ,			// id
		(int)(1.0f * (1<<10)),	// rate
		0,		// handle
		255,	// volume
		128,	// panning
	};
}

mm_sfxhand SoundControl::playGunsht() { return mmEffectEx(&snd_gunsht); }
mm_sfxhand SoundControl::playAmmoOut() { return mmEffectEx(&snd_ammoout); }
mm_sfxhand SoundControl::playHurt() { return mmEffectEx(&snd_hurt); }
mm_sfxhand SoundControl::playJump() { return mmEffectEx(&snd_jump); }
mm_sfxhand SoundControl::playEmptyChamber() { return mmEffectEx(&snd_gunempty); }

void SoundControl::loadStream(const char* path, bool loop) {
	if (stream_source) {
		stream_is_playing = false;
		mmStreamClose();
		fclose(stream_source);
	}

	resetStreamSettings();

	stream_source = fopen(path, "rb");
	if (!stream_source) return;

	u8 wavFormat = 0;
	u8 numChannels = 1;
	fseek(stream_source, 0x14, SEEK_SET);
	fread(&wavFormat, sizeof(u8), 1, stream_source);
	fseek(stream_source, 0x16, SEEK_SET);
	fread(&numChannels, sizeof(u8), 1, stream_source);
	stream.format = numChannels == 2 ? MM_STREAM_8BIT_STEREO : MM_STREAM_16BIT_MONO;
	fseek(stream_source, 0x18, SEEK_SET);
	fread(&stream.sampling_rate, sizeof(u16), 1, stream_source);
	fseek(stream_source, 0x28, SEEK_SET);
	fread(&stream_size, sizeof(size_t), 1, stream_source);
	if (wavFormat == 0x11) {
		return;
	}

	fseek(stream_source, 0x2C, SEEK_SET);
	stream.buffer_length = 1600;	  		// should be adequate
	stream.callback = on_stream_request;    
	stream.timer = MM_TIMER0;	    	   // use timer0
	stream.manual = false;	      		   // auto filling
	looping = loop;

	// Prep the first section of the stream
	toncset((void*)play_stream_buf, 0, STREAMING_BUF_LENGTH*sizeof(s16));
	fread((void*)play_stream_buf, sizeof(s16), STREAMING_BUF_LENGTH, stream_source);

	// Fill the next section premptively
	toncset((void*)fill_stream_buf, 0, STREAMING_BUF_LENGTH*sizeof(s16));
	fread((void*)fill_stream_buf, sizeof(s16), STREAMING_BUF_LENGTH, stream_source);
}

void SoundControl::beginStream() {
	if (!stream_source) return;

	// open the stream
	stream_is_playing = true;
	mmStreamOpen(&stream);
	SetYtrigger(0);
}

void SoundControl::stopStream() {
	if (!stream_source) return;

	stream_is_playing = false;
	mmStreamClose();
}

void SoundControl::fadeOutStream() {
	fade_out = true;
}

void SoundControl::cancelFadeOutStream() {
	fade_out = false;
	fade_counter = FADE_STEPS;
}

void SoundControl::setStreamDelay(u32 delay) {
	sample_delay_count = delay;
}


// Samples remaining in the fill buffer.
#define SAMPLES_LEFT_TO_FILL (abs(STREAMING_BUF_LENGTH - filled_samples))

// Samples that were already streamed and need to be refilled into the buffer.
#define SAMPLES_TO_FILL (abs(streaming_buf_ptr - filled_samples))

// Updates the background music fill buffer
// Fill the amount of samples that were used up between the
// last fill request and this.

// Precondition Invariants:
// filled_samples <= STREAMING_BUF_LENGTH
// filled_samples <= streaming_buf_ptr

// Postcondition Invariants:
// filled_samples <= STREAMING_BUF_LENGTH
// filled_samples <= streaming_buf_ptr
// fill_requested == false
volatile void SoundControl::updateStream() {
	
	if (!stream_is_playing) return;
	if (fill_requested && filled_samples < STREAMING_BUF_LENGTH) {
			
		// Reset the fill request
		fill_requested = false;
		int instance_filled = 0;

		// Either fill the max amount, or fill up the buffer as much as possible.
		int instance_to_fill = std::min(SAMPLES_LEFT_TO_FILL, SAMPLES_TO_FILL);

		// If we don't read enough samples, loop from the beginning of the file.
		instance_filled = fread((s16*)fill_stream_buf + filled_samples, sizeof(s16), instance_to_fill, stream_source);		
		if (instance_filled < instance_to_fill || ftell(stream_source) >= 0x2C+stream_size) {
			if (looping) {
				fseek(stream_source, 0x2C, SEEK_SET);
				int i = fread((s16*)fill_stream_buf + filled_samples + instance_filled,
					 sizeof(s16), (instance_to_fill - instance_filled), stream_source);
				if (i==0) {
					toncset((s16*)fill_stream_buf + filled_samples + instance_filled, 0, (instance_to_fill - instance_filled)*sizeof(s16));
				} else {
					instance_filled += i;
				}
			} else {
				toncset((s16*)fill_stream_buf + filled_samples + instance_filled, 0, (instance_to_fill - instance_filled)*sizeof(s16));
			}
		}

		#ifdef SOUND_DEBUG
		sprintf(debug_buf, "FC: SAMPLES_LEFT_TO_FILL: %li, SAMPLES_TO_FILL: %li, instance_filled: %i, filled_samples %li, to_fill: %i", SAMPLES_LEFT_TO_FILL, SAMPLES_TO_FILL, instance_filled, filled_samples, instance_to_fill);
    	nocashMessage(debug_buf);
		#endif

		// maintain invariant 0 < filled_samples <= STREAMING_BUF_LENGTH
		filled_samples = std::min<s32>(filled_samples + instance_filled, STREAMING_BUF_LENGTH);

	
	} else if (fill_requested && filled_samples >= STREAMING_BUF_LENGTH) {
		// filled_samples == STREAMING_BUF_LENGTH is the only possible case
		// but we'll keep it at gte to be safe.
		filled_samples = 0;
		// fill_count = 0;
	}

}
