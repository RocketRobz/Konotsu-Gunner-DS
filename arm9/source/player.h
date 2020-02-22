#ifndef PLAYER_H
#define PLAYER_H

extern void setPlayerPosition(int x, int y);
extern void playerGraphicLoad(void);
extern void playerLoop(int pressed, int held);
extern void renderPlayer(void);

#endif	// PLAYER_H