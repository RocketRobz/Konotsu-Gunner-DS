#pragma once
#ifndef __KONOTSU_SOUND__
#define __KONOTSU_SOUND__
#include <nds.h>
#include <mm_types.h>
#include <maxmod9.h>
#include "singleton.h"
#include <cstdio>

/*
 * Handles playing sound effects and the streaming background music control.
 * See streamingaudio.c for a technical overview of how streaming works.
 */
class SoundControl {
    public:
        SoundControl();
        mm_sfxhand playGunsht();
        mm_sfxhand playAmmoOut();
        mm_sfxhand playHurt();
        mm_sfxhand playJump();
        mm_sfxhand playEmptyChamber();
        
        // Refill the stream buffers
        volatile void updateStream();

        void loadStream(const char* path, bool loop);
        void beginStream();
        void stopStream();
        void fadeOutStream();
        void cancelFadeOutStream();

        // Sets the number of samples of silence to
        // stream before continuing.
        void setStreamDelay(u32 stream_delay);

    private:
        mm_sound_effect snd_gunsht;
        mm_sound_effect snd_ammoout;
        mm_sound_effect snd_hurt;
        mm_sound_effect snd_jump;
        mm_sound_effect snd_gunempty;
        mm_stream stream;
        mm_ds_system sys;
        bool stream_is_playing;
        bool looping;
		size_t stream_size;
        FILE* stream_source;
};

typedef singleton<SoundControl> soundCtl_s;
inline SoundControl &snd() { return soundCtl_s::instance(); }

#endif