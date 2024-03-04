#include "maze.h"
#include <SDL2/SDL.h>

static SDL_Window *window;
static SDL_Renderer *renderer;

/* Forward declaration of cleanupSDL */
static void cleanupSDL(void);

/**
 * initializeSDL - initializes SDL
 * Return: (0) on success, exits with failure status on failure
 */
static bool initializeSDL(void)
{
	if (SDL_Init(SDL_INIT_VIDEO | SDL_INIT_AUDIO) != 0)
	{
		fprintf(stderr, "SDL_Init Error: %s\n", SDL_GetError());
		cleanupSDL(); /* Now the compiler knows about cleanupSDL */
		return (false);
	}

	window = SDL_CreateWindow("Maze Game", SDL_WINDOWPOS_UNDEFINED,
				  SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH,
				  SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
	if (window == NULL)
	{
		fprintf(stderr, "SDL_CreateWindow Error: %s\n", SDL_GetError());
		cleanupSDL();
		return (false);
	}

	renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
	if (renderer == NULL)
	{
		fprintf(stderr, "SDL_CreateRenderer Error: %s\n",
			SDL_GetError());
		cleanupSDL();
		return (false);
	}

	SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);

	return (true);
}

/**
 * cleanupSDL - cleans up SDL resources
 */
static void cleanupSDL(void)
{
	if (renderer != NULL)
	{
		SDL_DestroyRenderer(renderer);
	}

	if (window != NULL)
	{
		SDL_DestroyWindow(window);
	}

	SDL_Quit();
}

/**
 * gameLoop - the main game loop
 */
static void gameLoop(void)
{
	bool quit = false;
	SDL_Event event;

	while (!quit)
	{
		while (SDL_PollEvent(&event) != 0)
		{
			if (event.type == SDL_QUIT)
			{
				quit = true;
			}
			/* Add more event handling as needed */
		}

		/* TODO: Update game state */

		/* TODO: Render the scene */
		/**
		 * Aim for around 60 frames per second
		 * (1000 ms/60 fps = 16.67 ms per frame)
		 */
		SDL_Delay(16);
	}
}

/**
 * main - SDL INITIALIZE
 * Return: (0) on success, exits with failure status on failure
 */
int main(void)
{
	if (!initializeSDL())
	{
		fprintf(stderr, "Failed to initialize SDL.\n");
		return (1);
	}

	gameLoop();

	cleanupSDL();
	return (0);
}
