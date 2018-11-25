#include "TextureManager.h"

SDL_Texture* TextureManager::loadTexture(const char* location)
{
	SDL_Surface* surface = IMG_Load(location);
	SDL_Texture* texture = SDL_CreateTextureFromSurface(Game::renderer,surface);
	SDL_FreeSurface(surface);

	return texture;
}

void TextureManager::draw(SDL_Texture* texture, SDL_Rect src, SDL_Rect dest)
{
	SDL_RenderCopy(Game::renderer, texture, &src, &dest);
}