#ifndef _MAIN_H_
#define _MAIN_H_

#include <SDL2/SDL.h>
#include <stdio.h>

/* playsounds */
void playSound(const char *filename);
/* RAIN */
void startRain(void);
void handleRain(void);

#endif /*_MAIN_H_*/
