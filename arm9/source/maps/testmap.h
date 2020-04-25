#ifndef TESTMAP_H
#define TESTMAP_H

#include <nds.h>

#include "../tilenum.h"

// Map size (tile count): 32x24

int testMap_player1X = 128;
int testMap_player1Y = 0;
int testMap_player2X = 64;
int testMap_player2Y = 0;

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