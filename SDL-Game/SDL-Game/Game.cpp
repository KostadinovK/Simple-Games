#include "Game.h"
#include "Map.h"

GameObject* player;
Map* map;

SDL_Renderer* Game::renderer = nullptr;

Game::Game() : isRunning(true), window(nullptr){}

void Game::init(const char* title, int xpos, int ypos, int width, int height, bool isFullscreen)
{
	if(SDL_Init(SDL_INIT_EVERYTHING) == 0)
	{
		int flag = 0;
		if (isFullscreen) flag = 1;
		std::cout << "Subsystems initialized successfully!" << std::endl;

		this->window = SDL_CreateWindow(title, xpos, ypos, width, height, flag);

		if(window) std::cout << "Window created successfully!" << std::endl;
		
			
		this->renderer = SDL_CreateRenderer(this->window, -1, 0);

		if(this->renderer)
		{
			SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
			std::cout << "Renderer created successfully!" << std::endl;
		}

		this->isRunning = true;
		
		player = new GameObject("assets\\player.png", 0, 0);
		map = new Map();

	}else
	{
		std::cerr << "Subsystems initialized failed!..." << std::endl;
		this->isRunning = false;
	}
}

void Game::handleEvent()
{
	SDL_Event event;
	SDL_PollEvent(&event);

	switch (event.type)
	{
	case SDL_QUIT:
		this->isRunning = false;
		break;
	default:
		break;
	}
}

void Game::update()
{
	player->update();
}

void Game::render()
{
	SDL_RenderClear(this->renderer);
	map->drawMap();
	player->render();
	SDL_RenderPresent(this->renderer);
}

bool Game::running() const
{
	return this->isRunning;
}

void Game::clean()
{
	SDL_DestroyWindow(this->window);
	SDL_DestroyRenderer(this->renderer);
	SDL_Quit();
	delete player;
	player = nullptr;
	delete map;
	map = nullptr;
	std::cout << "Game cleaned successfully!" << std::endl;
}

Game::~Game() {}
