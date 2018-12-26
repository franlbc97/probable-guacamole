#include "GraphicManager.h"
#include <SDL.h>
static SDL_Window* window_;
static SDL_Renderer* renderer_;
static SDL_Rect cameraRect_;
bool GraphicManager::init()
{
	
	SDL_Init(SDL_INIT_EVERYTHING);
	window_ = SDL_CreateWindow("Game Window", 0, 0, 1280, 720, SDL_WINDOW_OPENGL);
	

	renderer_ = SDL_CreateRenderer(window_, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);

	SDL_SetRenderDrawColor(renderer_, 0, 100, 100, 255);  // Dark grey.
	cameraRect_ = { 0,0,1280,720 };
	SDL_RenderClear(renderer_);
	SDL_RenderPresent(renderer_);
	return false;
}

bool GraphicManager::tick()
{
	return false;
}

SDL_Renderer * GraphicManager::getRenderer()
{
	return renderer_;
}

SDL_Window * GraphicManager::getWindow()
{
	return window_;
}

void GraphicManager::moveCamera(const int & x, const int & y)
{
	cameraRect_.x += x;
	cameraRect_.y += y;
}

void GraphicManager::setCameraPos(const int & x, const int & y)
{
	cameraRect_.x = x;
	cameraRect_.y = y;
}

SDL_Rect GraphicManager::getRectRelativeToCamera(const SDL_Rect & r)
{
	
	return {r.x-cameraRect_.x,r.y - cameraRect_.y,r.w,r.h};
}

bool GraphicManager::isInCamera(const SDL_Rect & r)
{
	SDL_Rect inter;
	if (SDL_TRUE == SDL_IntersectRect(&r, &cameraRect_, &inter)) {
		return true;
	}
	return false;
}
