#ifndef PLAYER_H
#define PLAYER_H

extern void initPlayers(int numberOfChars);
extern void setPlayerPosition(int id, int x, int y);
extern void playerGraphicLoad(void);
extern void playerLoop(int pressed, int held);
extern void renderPlayer(void);

#endif	// PLAYER_H