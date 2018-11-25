#include "GameObject.h"

GameObject::GameObject(const char* textureLocation,int x,int y) : xpos(x),ypos(y)
{
	
	this->texture = TextureManager::loadTexture(textureLocation);

	this->srcRect.x = 0;
	this->srcRect.y = 0;
	this->srcRect.w = 32;
	this->srcRect.h = 32;

	this->destRect.x = this->xpos;
	this->destRect.y = this->ypos;
	this->destRect.w = this->srcRect.w * 2;
	this->destRect.h = this->srcRect.h * 2;
}

void GameObject::render()
{
	TextureManager::draw(this->texture,srcRect,destRect);
}

void GameObject::update()
{
	this->destRect.x = this->xpos;
	this->destRect.y = this->ypos;
}
GameObject::~GameObject() = default;