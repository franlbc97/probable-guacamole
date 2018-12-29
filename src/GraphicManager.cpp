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

bool GraphicManager::release()
{
	SDL_Quit();
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

void GraphicManager::present()
{
	SDL_RenderPresent(renderer_);
}

void GraphicManager::clear()
{
	SDL_SetRenderDrawColor(renderer_, 0, 100, 100, 255);  // Dark grey.
	SDL_RenderClear(renderer_);
}

void GraphicManager::setColor(const int & r, const int & g, const int & b, const int & a)
{
	SDL_SetRenderDrawColor(renderer_, r, g, b, a);
}

void GraphicManager::drawRect(const SDL_Rect & rect,const SDL_Color & color)
{
	setColor(color.r, color.g, color.b, color.a);
	SDL_RenderFillRect(renderer_, &rect);
}

void GraphicManager::drawLine(const int & x1, const int & y1, const int & x2, const int & y2, const SDL_Color & color)
{
	SDL_SetRenderDrawColor(renderer_, color.r, color.g, color.b, color.a);
	SDL_RenderDrawLine(renderer_, x1, y1, x2, y2);
}
