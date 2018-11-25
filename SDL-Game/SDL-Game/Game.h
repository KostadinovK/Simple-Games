#pragma once
#include <SDL.h>
#include <SDL_image.h>
#include <string>
#include <iostream>

#include "TextureManager.h"
#include "GameObject.h"

typedef SDL_Window Window;
typedef SDL_Renderer Renderer;


class Game
{
	bool isRunning;
	Window* window;
	Renderer* renderer;
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