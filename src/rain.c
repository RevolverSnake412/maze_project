#include "maze.h"
/**
 * handleRain - function to handle rain effect
 *
 */
void handleRain(void)
{
	SDL_Rect raindropRect;

	raindropRect.w = 16;
	raindropRect.h = 16;

	for (int i = 0; i < 100; ++i)
	{
		raindropRect.x = rand() % SCREEN_WIDTH;
		raindropRect.y = rand() % SCREEN_HEIGHT;

		SDL_RenderCopy(renderer, raindropTexture, NULL, &raindropRect);
	}
}
/**
 * startRain - Function to start the rain effect
 *
 */
void startRain(void)
{
	SDL_Event e;

	/* Start the rain sound */
	Mix_PlayMusic(rainSound, -1); /* -1 for looping */

	/* Main game loop */
	while (1)
	{
		while (SDL_PollEvent(&e) != 0)
		{
			if (e.type == SDL_QUIT)
			{
				return; /* Exit the function if the window is closed */
			}
			else if (e.type == SDL_KEYDOWN &&
				 e.key.keysym.sym == SDLK_r)
			{
				return; /* Exit the function if 'R' is presse again to stop the rain */
			}
		}

		SDL_RenderClear(renderer);

		/* Render your game scene here */

		handleRain(); /* Render rain effect */

		SDL_RenderPresent(renderer);
	}
}
