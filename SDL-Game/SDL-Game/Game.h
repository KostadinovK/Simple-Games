#pragma once
#include <SDL.h>
#include <SDL_image.h>
#include <string>
#include <iostream>

typedef SDL_Window Window;
typedef SDL_Renderer Renderer;


class Game
{
	bool isRunning;
	Window* window;
	Renderer* renderer;
	SDL_Texture* player;
	SDL_Rect srcRec;
	SDL_Rect desRec;
	long counter;

public:
	Game();

	void init(const char* title, int xpos, int ypos, int width, int height,bool isFullscreen);
	void handleEvent();
	void update();
	void render();
	void clean();
	bool running() const;
	~Game();
};