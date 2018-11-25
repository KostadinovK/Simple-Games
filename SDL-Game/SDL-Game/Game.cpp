#include "Game.h"

Game::Game() : isRunning(true),window(nullptr),renderer(nullptr){}

void Game::init(const char* title, int xpos, int ypos, int width, int height, bool isFullscreen)
{
	if(SDL_Init(SDL_INIT_EVERYTHING) == 0)
	{
		int flag = 0;
		if(isFullscreen)
		{
			std::cout << "Sybsystems initialized!..." << std::endl;
			flag = SDL_WINDOW_FULLSCREEN;
		}
		this->window = SDL_CreateWindow(title,xpos,ypos,width,height,flag);

		if(this->window) std::cout << "Window created successfully!" << std::endl;
			
		this->renderer = SDL_CreateRenderer(this->window, -1, 0);

		if (this->renderer)
		{
			SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
			std::cout << "Renderer created successfully!" << std::endl;
		}

		this->isRunning = true;
	}else
	{
		std::cerr << "Subsystems initialized failed!..." << std::endl;
		this->isRunning = false;
	}
}

void Game::update()
{
	//TODO
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
void Game::render()
{
	SDL_RenderClear(this->renderer);
	//Add objects to render
	SDL_RenderPresent(this->renderer);
}
void Game::clean()
{
	SDL_DestroyWindow(this->window);
	SDL_DestroyRenderer(this->renderer);
	SDL_Quit();

	std::cout << "Game cleaned successfully!" << std::endl;
}
bool Game::running() const
{
	return this->isRunning;
}

Game::~Game(){}