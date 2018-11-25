#pragma once
#include <SDL.h>
#include <string>
#include <iostream>

typedef SDL_Window Window;
typedef SDL_Renderer Renderer;

class Game
{
	bool isRunning;
	Window* window;
	Renderer* renderer;

public:
	Game();

	void init(const char* title, int xpos,int ypos, int width,int height,bool isFullscreen);
	void update();
	void handleEvent();
	void render();
	void clean();
	bool running() const;

	~Game();
};