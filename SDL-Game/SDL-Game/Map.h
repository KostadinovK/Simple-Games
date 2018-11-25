#pragma once
#include <SDL_image.h>
#include <SDL.h>

#include "TextureManager.h"

class Map
{
	int map[20][25];

	SDL_Texture* waterTexture;
	SDL_Texture* dirtTexture;
	SDL_Texture* grassTexture;
	SDL_Rect src;
	SDL_Rect dest;

public:
	static const int WATER = 0;
	static const int GRASS = 1;
	static const int DIRT = 2;
	static const int HEIGHT = 20;
	static const int WIDTH = 25;

	Map();
	void loadMap(const int arr[20][25]);
	void drawMap();
	~Map();
};