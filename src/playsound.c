#include "maze.h"
/**
 * playSound - function to play a wav format audio
 * @filename: audio file to play
 *
 */
void playSound(const char *filename)
{
	SDL_Init(SDL_INIT_AUDIO);

	SDL_AudioSpec wavSpec;
	Uint8 *wavStart;
	Uint32 wavLength;

	if (SDL_LoadWAV(filename, &wavSpec, &wavStart, &wavLength) == NULL)
	{
		/* Handle error loading WAV file*/
		SDL_Quit();
		return;
	}

	SDL_AudioDeviceID deviceId =
	    SDL_OpenAudioDevice(NULL, 0, &wavSpec, NULL, 0);
	if (deviceId == 0)
	{
		/* Handle error opening audio device */
		SDL_FreeWAV(wavStart);
		SDL_Quit();
		return;
	}

	SDL_QueueAudio(deviceId, wavStart, wavLength);
	SDL_PauseAudioDevice(deviceId, 0);

	/* Wait for audio to finish*/
	SDL_Delay(wavLength / wavSpec.freq * 1000);

	SDL_CloseAudioDevice(deviceId);
	SDL_FreeWAV(wavStart);
	SDL_Quit();
}
