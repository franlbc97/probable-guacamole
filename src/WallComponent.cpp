#include "WallComponent.h"

WallComponent::WallComponent(FMOD::Geometry * geometrys):_geo(_geo)
{
	
}

WallComponent::~WallComponent()
{
}

bool WallComponent::init(AppObject * obj)
{
	FMOD_VECTOR verts[4];
	verts[0].x = 0;
	verts[0].y = 100;
	verts[0].z = 500;

	verts[1].x = 0;
	verts[1].y = -100;
	verts[1].z = 500;

	verts[2].x = 1000;
	verts[2].y = -100;
	verts[2].z = 500;

	verts[3].x = 1000;
	verts[3].y = 100;
	verts[3].z = 500;
	_geo->addPolygon(directOclusion, reverbOcclusion, true, 4, verts, &polygonIndex);
	return false;
}

void WallComponent::render(SDL_Renderer * r, AppObject * obj)
{
}

void WallComponent::tick(AppObject * obj)
{
}

bool WallComponent::handleInput(SDL_Event & e, AppObject * obj)
{
	return false;
}

void WallComponent::release(AppObject * obj)
{
}
