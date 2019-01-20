#pragma once
#include "Component.h"
#include <SDL_render.h>
class RectRenderComponent :public Component
{
public:
	/// <summary>
	/// The constructor of the RectRendererComponent
	/// </summary>
	/// <param name="color"></param>
	RectRenderComponent(SDL_Color color) ;
	/// <summary>
	/// The destructor of the RectRendererComponent
	/// </summary>
	virtual ~RectRenderComponent() {};
	/// <summary>
	/// For initializing the Component
	/// </summary>
	/// <param name="obj">he object that is asociated with componen</param>
	/// <returns>True if fails, False in every other case</returns>
	virtual bool init(AppObject * obj);

	/// <summary>
	/// Renders The rectangle of the Object
	/// </summary>
	/// <param name="obj">e object that is asociated with componen</param>
	virtual void render(AppObject * obj);

	/// <summary>
	/// Doesnt do nothng
	/// </summary>
	/// <param name="obj">The object that is asociated with component</param>
	virtual void tick(AppObject * obj);
	/// <summary>
	/// Doesnt do nothing
	/// </summary>
	/// <param name="e"></param>
	/// <param name="obj"></param>
	/// <returns></returns>
	virtual bool handleInput(SDL_Event & e, AppObject * obj);

	/// <summary>
	/// Release everything about this component
	/// </summary>
	/// <param name="obj"></param>
	virtual void release(AppObject * obj);
	virtual const char * getType();

private:
	SDL_Color _color;
	SDL_Surface * surface;
};