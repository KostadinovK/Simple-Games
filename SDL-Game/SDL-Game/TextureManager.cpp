#include "TextureManager.h"

SDL_Texture* TextureManager::loadTexture(const char* location, SDL_Renderer* renderer)
{
	SDL_Surface* surface = IMG_Load(location);
	SDL_Texture* texture = SDL_CreateTextureFromSurface(renderer,surface);
	SDL_FreeSurface(surface);

	return texture;
}
