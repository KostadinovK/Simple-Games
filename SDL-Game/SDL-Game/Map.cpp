#include "Map.h"

const int lvl1[Map::HEIGHT][Map::WIDTH]
{
	{Map::DIRT,Map::DIRT,Map::WATER,Map::WATER,Map::WATER,Map::WATER,Map::WATER,Map::WATER,Map::WATER,Map::WATER,Map::WATER,Map::WATER,Map::WATER,Map::WATER,Map::WATER,Map::WATER,Map::WATER,Map::WATER,Map::WATER,Map::WATER,Map::WATER,Map::WATER,Map::WATER,Map::WATER,Map::WATER},
	{Map::GRASS,Map::GRASS,Map::WATER,Map::WATER,Map::WATER,Map::WATER,Map::WATER,Map::WATER,Map::WATER,Map::WATER,Map::WATER,Map::WATER,Map::WATER,Map::WATER,Map::WATER,Map::WATER,Map::WATER,Map::WATER,Map::WATER,Map::WATER,Map::WATER,Map::WATER,Map::WATER,Map::WATER,Map::WATER},
	{Map::WATER,Map::WATER,Map::WATER,Map::WATER,Map::WATER,Map::WATER,Map::WATER,Map::WATER,Map::WATER,Map::WATER,Map::WATER,Map::WATER,Map::WATER,Map::WATER,Map::WATER,Map::WATER,Map::WATER,Map::WATER,Map::WATER,Map::WATER,Map::WATER,Map::WATER,Map::WATER,Map::WATER,Map::WATER},
	{Map::WATER,Map::WATER,Map::WATER,Map::WATER,Map::WATER,Map::WATER,Map::WATER,Map::WATER,Map::WATER,Map::WATER,Map::WATER,Map::WATER,Map::WATER,Map::WATER,Map::WATER,Map::WATER,Map::WATER,Map::WATER,Map::WATER,Map::WATER,Map::WATER,Map::WATER,Map::WATER,Map::WATER,Map::WATER},
	{Map::WATER,Map::WATER,Map::WATER,Map::WATER,Map::WATER,Map::WATER,Map::WATER,Map::WATER,Map::WATER,Map::WATER,Map::WATER,Map::WATER,Map::WATER,Map::WATER,Map::WATER,Map::WATER,Map::WATER,Map::WATER,Map::WATER,Map::WATER,Map::WATER,Map::WATER,Map::WATER,Map::WATER,Map::WATER},
	{Map::WATER,Map::WATER,Map::WATER,Map::WATER,Map::WATER,Map::WATER,Map::WATER,Map::WATER,Map::WATER,Map::WATER,Map::WATER,Map::WATER,Map::WATER,Map::WATER,Map::WATER,Map::WATER,Map::WATER,Map::WATER,Map::WATER,Map::WATER,Map::WATER,Map::WATER,Map::WATER,Map::WATER,Map::WATER},
	{Map::WATER,Map::WATER,Map::GRASS,Map::DIRT,Map::WATER,Map::WATER,Map::WATER,Map::WATER,Map::WATER,Map::WATER,Map::WATER,Map::WATER,Map::WATER,Map::WATER,Map::WATER,Map::WATER,Map::WATER,Map::WATER,Map::WATER,Map::WATER,Map::WATER,Map::WATER,Map::WATER,Map::WATER,Map::WATER},
	{Map::WATER,Map::WATER,Map::GRASS,Map::DIRT,Map::WATER,Map::WATER,Map::WATER,Map::WATER,Map::WATER,Map::WATER,Map::WATER,Map::WATER,Map::WATER,Map::WATER,Map::WATER,Map::WATER,Map::WATER,Map::WATER,Map::WATER,Map::WATER,Map::WATER,Map::WATER,Map::WATER,Map::WATER,Map::WATER},
	{Map::WATER,Map::WATER,Map::WATER,Map::WATER,Map::WATER,Map::WATER,Map::WATER,Map::WATER,Map::WATER,Map::WATER,Map::WATER,Map::WATER,Map::WATER,Map::WATER,Map::WATER,Map::WATER,Map::WATER,Map::WATER,Map::WATER,Map::WATER,Map::WATER,Map::WATER,Map::WATER,Map::WATER,Map::WATER},
	{Map::WATER,Map::WATER,Map::WATER,Map::WATER,Map::WATER,Map::WATER,Map::WATER,Map::WATER,Map::WATER,Map::WATER,Map::WATER,Map::WATER,Map::WATER,Map::WATER,Map::WATER,Map::WATER,Map::WATER,Map::WATER,Map::WATER,Map::WATER,Map::WATER,Map::WATER,Map::WATER,Map::WATER,Map::WATER},
	{Map::WATER,Map::WATER,Map::WATER,Map::WATER,Map::WATER,Map::WATER,Map::WATER,Map::WATER,Map::WATER,Map::WATER,Map::WATER,Map::WATER,Map::WATER,Map::WATER,Map::WATER,Map::WATER,Map::WATER,Map::WATER,Map::WATER,Map::WATER,Map::WATER,Map::WATER,Map::WATER,Map::WATER,Map::WATER},
	{Map::WATER,Map::WATER,Map::WATER,Map::WATER,Map::WATER,Map::WATER,Map::WATER,Map::WATER,Map::WATER,Map::WATER,Map::WATER,Map::WATER,Map::WATER,Map::WATER,Map::WATER,Map::WATER,Map::WATER,Map::WATER,Map::WATER,Map::WATER,Map::WATER,Map::WATER,Map::WATER,Map::WATER,Map::WATER},
	{Map::WATER,Map::WATER,Map::WATER,Map::WATER,Map::WATER,Map::WATER,Map::WATER,Map::WATER,Map::WATER,Map::WATER,Map::WATER,Map::WATER,Map::WATER,Map::WATER,Map::WATER,Map::WATER,Map::WATER,Map::WATER,Map::WATER,Map::WATER,Map::WATER,Map::WATER,Map::WATER,Map::WATER,Map::WATER},
	{Map::WATER,Map::WATER,Map::WATER,Map::WATER,Map::WATER,Map::WATER,Map::WATER,Map::WATER,Map::WATER,Map::WATER,Map::WATER,Map::WATER,Map::WATER,Map::WATER,Map::WATER,Map::WATER,Map::WATER,Map::WATER,Map::WATER,Map::WATER,Map::WATER,Map::WATER,Map::WATER,Map::WATER,Map::WATER},
	{Map::WATER,Map::WATER,Map::WATER,Map::WATER,Map::WATER,Map::WATER,Map::WATER,Map::WATER,Map::WATER,Map::WATER,Map::WATER,Map::WATER,Map::WATER,Map::WATER,Map::WATER,Map::WATER,Map::WATER,Map::WATER,Map::WATER,Map::WATER,Map::WATER,Map::WATER,Map::WATER,Map::WATER,Map::WATER},
	{Map::WATER,Map::WATER,Map::WATER,Map::WATER,Map::WATER,Map::WATER,Map::WATER,Map::WATER,Map::WATER,Map::WATER,Map::WATER,Map::WATER,Map::WATER,Map::WATER,Map::WATER,Map::WATER,Map::WATER,Map::WATER,Map::WATER,Map::WATER,Map::WATER,Map::WATER,Map::WATER,Map::WATER,Map::WATER},
	{Map::WATER,Map::WATER,Map::WATER,Map::WATER,Map::WATER,Map::WATER,Map::WATER,Map::WATER,Map::WATER,Map::WATER,Map::WATER,Map::WATER,Map::WATER,Map::WATER,Map::WATER,Map::WATER,Map::WATER,Map::WATER,Map::WATER,Map::WATER,Map::WATER,Map::WATER,Map::WATER,Map::WATER,Map::WATER},
	{Map::WATER,Map::WATER,Map::WATER,Map::WATER,Map::WATER,Map::WATER,Map::WATER,Map::WATER,Map::WATER,Map::WATER,Map::WATER,Map::WATER,Map::WATER,Map::WATER,Map::WATER,Map::WATER,Map::WATER,Map::WATER,Map::WATER,Map::WATER,Map::WATER,Map::WATER,Map::WATER,Map::WATER,Map::WATER},
	{Map::WATER,Map::WATER,Map::WATER,Map::WATER,Map::WATER,Map::WATER,Map::WATER,Map::WATER,Map::WATER,Map::WATER,Map::WATER,Map::WATER,Map::WATER,Map::WATER,Map::WATER,Map::WATER,Map::WATER,Map::WATER,Map::WATER,Map::WATER,Map::WATER,Map::WATER,Map::WATER,Map::WATER,Map::WATER},
	{Map::WATER,Map::WATER,Map::WATER,Map::WATER,Map::WATER,Map::WATER,Map::WATER,Map::WATER,Map::WATER,Map::WATER,Map::WATER,Map::WATER,Map::WATER,Map::WATER,Map::WATER,Map::WATER,Map::WATER,Map::WATER,Map::WATER,Map::WATER,Map::WATER,Map::WATER,Map::WATER,Map::WATER,Map::WATER}
};

Map::Map()
{
	this->waterTexture = TextureManager::loadTexture("assets\\water.png");
	this->dirtTexture = TextureManager::loadTexture("assets\\dirt.png");
	this->grassTexture = TextureManager::loadTexture("assets\\grass.png");

	this->src.x = this->dest.x = 0;
	this->src.y = this->dest.y = 0;
	this->src.h = this->dest.h = 32;
	this->src.w = this->dest.w = 32;

	this->loadMap(lvl1);
}
void Map::loadMap(const int arr[Map::HEIGHT][Map::WIDTH])
{
	for(int row = 0; row < HEIGHT;row++)
	{
		for(int col = 0;col < WIDTH;col++)
		{
			this->map[row][col] = arr[row][col];
		}
	}
}
void Map::drawMap()
{
	for (int row = 0; row < HEIGHT; row++)
	{
		for (int col = 0; col < WIDTH; col++)
		{
			dest.x = col * 32;
			dest.y = row * 32;
			if(this->map[row][col] == WATER)
			{
				TextureManager::draw(this->waterTexture, src, dest);
			}else if(this->map[row][col] == DIRT)
			{
				TextureManager::draw(this->dirtTexture, src, dest);
			}else if(this->map[row][col] == GRASS)
			{
				TextureManager::draw(this->grassTexture, src, dest);
			}
		}
	}
}

Map::~Map() = default;
