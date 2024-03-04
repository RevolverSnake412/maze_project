#ifndef _MAIN_H_
#define _MAIN_H_

#include "sdl.h"
#include <SDL2/SDL.h>
#include <SDL2/SDL_mixer.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>
/*  Main  */
int main(int argc, char *argv[]);
/*  SDL  */
int create_window(char *name, sdl_globals *sdl_g);
void safe_close_sdl(sdl_globals *sdl_g);
/* playsounds */
void playSound(const char *filename);
/* RAIN */
void startRain(void);
void handleRain(void);

#endif /*_MAIN_H_*/
