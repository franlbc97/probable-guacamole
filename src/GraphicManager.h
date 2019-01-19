#pragma once
#include <SDL_rect.h>
#include <SDL_render.h>

/// <summary>
/// For managing the rendering
/// </summary>
class GraphicManager
{
public:
	
	/// <summary>
	/// Initializes the graphics settings
	/// </summary>
	/// <returns></returns>
	static bool init();
	/// <summary>
	/// Executes every frame
	/// </summary>
	/// <returns> always false</returns>
	static bool tick();
	/// <summary>
	/// For releasing the everything thats involves 
	/// </summary>
	/// <returns>true if something went wrong</returns>
	static bool release();


	/// <summary>
	/// For getting the renderer
	/// </summary>
	/// <returns>the renderer</returns>
	static SDL_Renderer* getRenderer();

	/// <summary>
	/// For getting the main window of SDL
	/// </summary>
	/// <returns>The main window of SDL</returns>
	static SDL_Window * getWindow();
	
	/// <summary>
	/// For moving the camera of SDL
	/// </summary>
	/// <param name="x">The amount of movement in the X axis </param>
	/// <param name="y">The amount of movement in the Y axis</param>
	static void moveCamera(const int & x, const int & y);

	/// <summary>
	/// For setting the position of the camera of SDL
	/// </summary>
	/// <param name="x">The new postion in the axis X </param>
	/// <param name="y">The new postion in the axis Y</param>
	static void setCameraPos(const int & x, const int & y);

	/// <summary>
	/// For getting the position relative in camera of a SDLRect
	/// </summary>
	/// <param name="r">The rect</param>
	/// <returns>the recte with relative position</returns>
	static SDL_Rect getRectRelativeToCamera(const SDL_Rect & r);

	/// <summary>
	/// For checking if the rect is in camera
	/// </summary>
	/// <param name="r">the rect that is gonna be check</param>
	/// <returns>True if the rect is in camera, false in every other case</returns>
	static bool isInCamera(const SDL_Rect & r);


	
	/// <summary>
	/// For preseting the frame
	/// </summary>
	static void present();
	/// <summary>
	/// For clearing the frame
	/// </summary>
	static void clear();
	/// <summary>
	/// for setting the color of rendering
	/// </summary>
	/// <param name="r">The amount of red from 0 to 255</param>
	/// <param name="g">The amount of green from 0 to 255</param>
	/// <param name="b">The amount of blue from 0 to 255</param>
	/// <param name="a">The amount of alpha from 0 to 255</param>
	static void setColor(const int & r, const int & g, const int & b, const int & a);
	/// <summary>
	/// For drawing a rectangle with a color 
	/// </summary>
	/// <param name="rect">The rect that is gonna be draw</param>
	/// <param name="color">the color</param>
	static void drawRect(const SDL_Rect & rect, const SDL_Color & color);
	/// <summary>
	/// For drawing lines
	/// </summary>
	/// <param name="x1">initial X position</param>
	/// <param name="y1">initial Y position</param>
	/// <param name="x2">final X position</param>
	/// <param name="y2">final Y position</param>
	/// <param name="color">the color of the line</param>
	static void drawLine(const int &x1, const int &y1, const int &x2, const int &y2, const SDL_Color & color);
	/// <summary>
	/// For drawing a circunference
	/// </summary>
	/// <param name="x">The X position of the circunference</param>
	/// <param name="y">The Y position of the circunference</param>
	/// <param name="radius">The radius of the circunference</param>
	/// <param name="color">The color of the circunference</param>
	static void drawCircle(const int & x, const int & y, const int & radius, SDL_Color color);

};

