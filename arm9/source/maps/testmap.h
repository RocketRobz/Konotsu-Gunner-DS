#ifndef TESTMAP_H
#define TESTMAP_H

#include <nds.h>

#include "../tilenum.h"

// Map size (tile count): 32x24

u8 testMap[32*27] = {
	_AIR, _AIR, _AIR, _AIR, _AIR, _AIR, _AIR, _AIR, _AIR, _AIR, _AIR, _AIR, _AIR, _AIR, _AIR, _AIR, _AIR, _AIR, _AIR, _AIR, _AIR, _AIR, _AIR, _AIR, _AIR, _AIR, _AIR, _AIR, _AIR, _AIR, _AIR, _AIR,
	_AIR, _AIR, _AIR, _AIR, _AIR, _AIR, _AIR, _AIR, _AIR, _AIR, _AIR, _AIR, _AIR, _AIR, _AIR, _AIR, _AIR, _AIR, _AIR, _AIR, _AIR, _AIR, _AIR, _AIR, _AIR, _AIR, _AIR, _AIR, _AIR, _AIR, _AIR, _AIR,
	_AIR, _AIR, _AIR, _AIR, _AIR, _AIR, _AIR, _AIR, _AIR, _AIR, _AIR, _AIR, _AIR, _AIR, _AIR, _AIR, _AIR, _AIR, _AIR, _AIR, _AIR, _AIR, _AIR, _AIR, _AIR, _AIR, _AIR, _AIR, _AIR, _AIR, _AIR, _AIR,
	_AIR, _AIR, _AIR, _AIR, _AIR, _AIR, _AIR, _AIR, _AIR, _AIR, _AIR, _AIR, _AIR, _AIR, _AIR, _AIR, _AIR, _AIR, _AIR, _AIR, _AIR, _AIR, _AIR, _AIR, _AIR, _AIR, _AIR, _AIR, _AIR, _AIR, _AIR, _AIR,
	_AIR, _AIR, _AIR, _AIR, _AIR, _AIR, _AIR, _AIR, _AIR, _AIR, _AIR, _AIR, _AIR, _AIR, _AIR, _AIR, _AIR, _AIR, _AIR, _AIR, _AIR, _AIR, _AIR, _AIR, _AIR, _AIR, _AIR, _AIR, _AIR, _AIR, _AIR, _AIR,
	_AIR, _AIR, _AIR, _AIR, _AIR, _AIR, _AIR, _AIR, _AIR, _AIR, _AIR, _AIR, _AIR, _AIR, _BRK, _AIR, _AIR, _AIR, _AIR, _AIR, _AIR, _AIR, _AIR, _AIR, _AIR, _AIR, _AIR, _AIR, _AIR, _AIR, _AIR, _AIR,
	_AIR, _AIR, _AIR, _AIR, _AIR, _AIR, _AIR, _AIR, _AIR, _AIR, _BRK, _BRK, _BRK, _BRK, _BRK, _AIR, _AIR, _AIR, _AIR, _AIR, _AIR, _AIR, _AIR, _AIR, _AIR, _AIR, _AIR, _AIR, _AIR, _AIR, _AIR, _AIR,
	_AIR, _AIR, _AIR, _AIR, _BRK, _AIR, _AIR, _BRK, _BRK, _BRK, _AIR, _AIR, _AIR, _AIR, _AIR, _AIR, _AIR, _AIR, _AIR, _AIR, _AIR, _AIR, _AIR, _AIR, _AIR, _AIR, _AIR, _AIR, _AIR, _AIR, _AIR, _AIR,
	_AIR, _AIR, _AIR, _AIR, _BRK, _AIR, _AIR, _AIR, _AIR, _AIR, _AIR, _AIR, _AIR, _AIR, _AIR, _AIR, _AIR, _AIR, _AIR, _AIR, _AIR, _AIR, _AIR, _AIR, _AIR, _AIR, _AIR, _AIR, _AIR, _AIR, _AIR, _AIR,
	_AIR, _AIR, _AIR, _AIR, _AIR, _BRK, _AIR, _AIR, _AIR, _AIR, _AIR, _AIR, _AIR, _AIR, _AIR, _AIR, _AIR, _AIR, _AIR, _AIR, _AIR, _AIR, _AIR, _AIR, _AIR, _AIR, _AIR, _AIR, _AIR, _AIR, _AIR, _AIR,
	_AIR, _AIR, _AIR, _AIR, _AIR, _AIR, _BRK, _BRK, _BRK, _BRK, _BRK, _BRK, _BRK, _BRK, _BRK, _AIR, _BRK, _BRK, _AIR, _AIR, _BRK, _BRK, _AIR, _AIR, _AIR, _BRK, _BRK, _AIR, _AIR, _AIR, _AIR, _AIR,
	_AIR, _AIR, _AIR, _AIR, _AIR, _AIR, _AIR, _AIR, _AIR, _AIR, _AIR, _AIR, _AIR, _AIR, _AIR, _AIR, _AIR, _AIR, _AIR, _AIR, _AIR, _AIR, _AIR, _AIR, _AIR, _AIR, _AIR, _AIR, _AIR, _AIR, _AIR, _AIR,
	_AIR, _AIR, _AIR, _AIR, _AIR, _AIR, _AIR, _AIR, _AIR, _AIR, _AIR, _AIR, _AIR, _AIR, _AIR, _AIR, _AIR, _AIR, _AIR, _AIR, _AIR, _AIR, _AIR, _AIR, _AIR, _AIR, _AIR, _AIR, _AIR, _AIR, _AIR, _AIR,
	_AIR, _AIR, _AIR, _AIR, _AIR, _AIR, _AIR, _AIR, _AIR, _AIR, _AIR, _AIR, _AIR, _AIR, _AIR, _AIR, _AIR, _AIR, _AIR, _AIR, _AIR, _AIR, _AIR, _AIR, _AIR, _AIR, _AIR, _AIR, _AIR, _AIR, _AIR, _AIR,
	_AIR, _AIR, _AIR, _AIR, _AIR, _AIR, _AIR, _AIR, _AIR, _AIR, _AIR, _AIR, _AIR, _AIR, _AIR, _AIR, _AIR, _AIR, _AIR, _AIR, _AIR, _AIR, _AIR, _AIR, _AIR, _AIR, _AIR, _AIR, _AIR, _AIR, _AIR, _AIR,
	_AIR, _AIR, _AIR, _AIR, _AIR, _AIR, _AIR, _AIR, _AIR, _AIR, _AIR, _AIR, _AIR, _AIR, _AIR, _AIR, _AIR, _AIR, _AIR, _AIR, _AIR, _AIR, _AIR, _AIR, _AIR, _AIR, _AIR, _AIR, _AIR, _AIR, _AIR, _AIR,
	_AIR, _AIR, _AIR, _AIR, _AIR, _AIR, _AIR, _AIR, _AIR, _AIR, _AIR, _AIR, _AIR, _AIR, _AIR, _AIR, _AIR, _AIR, _AIR, _AIR, _AIR, _AIR, _AIR, _AIR, _AIR, _AIR, _AIR, _AIR, _AIR, _AIR, _AIR, _AIR,
	_AIR, _AIR, _AIR, _AIR, _AIR, _AIR, _AIR, _AIR, _AIR, _AIR, _AIR, _AIR, _AIR, _AIR, _AIR, _AIR, _AIR, _AIR, _AIR, _AIR, _AIR, _AIR, _AIR, _AIR, _AIR, _AIR, _AIR, _AIR, _AIR, _AIR, _AIR, _AIR,
	_AIR, _AIR, _AIR, _AIR, _AIR, _AIR, _AIR, _AIR, _AIR, _AIR, _AIR, _AIR, _AIR, _AIR, _AIR, _AIR, _AIR, _AIR, _AIR, _AIR, _AIR, _AIR, _AIR, _AIR, _AIR, _AIR, _AIR, _AIR, _AIR, _AIR, _AIR, _AIR,
	_AIR, _AIR, _AIR, _AIR, _AIR, _AIR, _AIR, _AIR, _AIR, _AIR, _AIR, _AIR, _AIR, _AIR, _AIR, _AIR, _AIR, _AIR, _AIR, _AIR, _AIR, _AIR, _AIR, _AIR, _AIR, _AIR, _AIR, _AIR, _AIR, _AIR, _AIR, _AIR,
	_AIR, _AIR, _AIR, _AIR, _AIR, _AIR, _AIR, _AIR, _AIR, _AIR, _AIR, _AIR, _AIR, _AIR, _AIR, _AIR, _AIR, _AIR, _AIR, _AIR, _AIR, _AIR, _AIR, _AIR, _AIR, _AIR, _AIR, _AIR, _AIR, _AIR, _AIR, _AIR,
	_AIR, _AIR, _AIR, _AIR, _AIR, _AIR, _AIR, _AIR, _AIR, _AIR, _AIR, _AIR, _AIR, _AIR, _AIR, _AIR, _AIR, _AIR, _AIR, _AIR, _AIR, _AIR, _AIR, _AIR, _AIR, _AIR, _AIR, _AIR, _AIR, _AIR, _AIR, _AIR,
	_AIR, _AIR, _AIR, _AIR, _AIR, _AIR, _AIR, _AIR, _AIR, _AIR, _AIR, _AIR, _AIR, _AIR, _AIR, _AIR, _AIR, _AIR, _AIR, _AIR, _AIR, _AIR, _AIR, _AIR, _AIR, _AIR, _AIR, _AIR, _AIR, _AIR, _AIR, _AIR,
	_AIR, _AIR, _AIR, _AIR, _AIR, _AIR, _AIR, _AIR, _AIR, _AIR, _AIR, _AIR, _AIR, _AIR, _AIR, _AIR, _AIR, _AIR, _AIR, _AIR, _AIR, _AIR, _AIR, _AIR, _AIR, _AIR, _AIR, _AIR, _AIR, _AIR, _AIR, _AIR,
	// Unseen
	_AIR, _AIR, _AIR, _AIR, _AIR, _AIR, _AIR, _AIR, _AIR, _AIR, _AIR, _AIR, _AIR, _AIR, _AIR, _AIR, _AIR, _AIR, _AIR, _AIR, _AIR, _AIR, _AIR, _AIR, _AIR, _AIR, _AIR, _AIR, _AIR, _AIR, _AIR, _AIR,
	_AIR, _AIR, _AIR, _AIR, _AIR, _AIR, _AIR, _AIR, _AIR, _AIR, _AIR, _AIR, _AIR, _AIR, _AIR, _AIR, _AIR, _AIR, _AIR, _AIR, _AIR, _AIR, _AIR, _AIR, _AIR, _AIR, _AIR, _AIR, _AIR, _AIR, _AIR, _AIR,
	KILL, KILL, KILL, KILL, KILL, KILL, KILL, KILL, KILL, KILL, KILL, KILL, KILL, KILL, KILL, KILL, KILL, KILL, KILL, KILL, KILL, KILL, KILL, KILL, KILL, KILL, KILL, KILL, KILL, KILL, KILL, KILL,
};

#endif	// TESTMAP_H