#include "WallComponent.h"
#include "AppObject.h"
#include "SoundManager.h"
#include "GraphicManager.h"
#include <iostream>
#define WALL_HEIGHT 10.f

WallComponent::WallComponent( const float & directOclusion, const float & reverbOcclusion) :
	_directOclusion(directOclusion),
	_reverbOcclusion(reverbOcclusion)

{
	
}


WallComponent::~WallComponent()
{
}

bool WallComponent::init(AppObject * obj)
{

	geo_ = SoundManager::createGeometry(4 * 2, 4 * 2 * 6);
	obj->setCanBeSeleceted(false);
	float x = obj->getX();
	float y = obj->getY();
	float xL = obj->getX() + obj->getW();
	float yL = obj->getY() + obj->getH();
	FMOD_VECTOR verts[4];


	verts[0].x = x;
	verts[0].y = WALL_HEIGHT;
	verts[0].z = y;

	verts[1].x = x;
	verts[1].y = -WALL_HEIGHT;
	verts[1].z = y;

	verts[2].x = xL;
	verts[2].y = -WALL_HEIGHT;
	verts[2].z = y;

	verts[3].x = xL;
	verts[3].y = WALL_HEIGHT;
	verts[3].z = y;
	SoundManager::CheckFMODErrors(geo_->addPolygon(_directOclusion, _reverbOcclusion, true, 4, verts, &polygonIndex));
	indexes[0] = polygonIndex;

	verts[0].x = x;
	verts[0].y = WALL_HEIGHT;
	verts[0].z = yL;

	verts[1].x = x;
	verts[1].y = -WALL_HEIGHT;
	verts[1].z = yL;

	verts[2].x = xL;
	verts[2].y = -WALL_HEIGHT;
	verts[2].z = yL;

	verts[3].x =xL;
	verts[3].y = WALL_HEIGHT;
	verts[3].z = yL;
	SoundManager::CheckFMODErrors(geo_->addPolygon(_directOclusion, _reverbOcclusion, true, 4, verts, &polygonIndex));
	indexes[1] = polygonIndex;

	verts[0].x = x;
	verts[0].y = WALL_HEIGHT;
	verts[0].z = y;

	verts[1].x = x;
	verts[1].y = -WALL_HEIGHT;
	verts[1].z = y;

	verts[2].x = x;
	verts[2].y = -WALL_HEIGHT;
	verts[2].z = yL;

	verts[3].x = x;
	verts[3].y = WALL_HEIGHT;
	verts[3].z = yL;
	SoundManager::CheckFMODErrors(geo_->addPolygon(_directOclusion, _reverbOcclusion, true, 4, verts, &polygonIndex));
	indexes[2] = polygonIndex;

	verts[0].x = xL;
	verts[0].y = WALL_HEIGHT;
	verts[0].z = y;

	verts[1].x = xL;
	verts[1].y = -WALL_HEIGHT;
	verts[1].z = y;

	verts[2].x = xL;
	verts[2].y = -WALL_HEIGHT;
	verts[2].z = yL;

	verts[3].x = xL;
	verts[3].y = WALL_HEIGHT;
	verts[3].z = yL;
	SoundManager::CheckFMODErrors(geo_->addPolygon(_directOclusion, _reverbOcclusion, true, 4, verts, &polygonIndex));
	indexes[3] = polygonIndex;
	return false;
}

void WallComponent::render(AppObject * obj)
{
	//GraphicManager::drawRect(obj->getRect(), { 0,0,0,255 });
	
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

const char * WallComponent::getType()
{
	return "WallComponent";
}
