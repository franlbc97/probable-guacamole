#include <SDL_rect.h>
class InputManager
{
public:
	static bool init();
	/// <summary>
	/// Gets the mouse position.
	/// </summary>
	/// <param name="offsetX">The offset x.</param>
	/// <param name="offsetY">The offset y.</param>
	/// <returns></returns>
	static SDL_Point getMousePosition(const int & offsetX = 0, const int & offsetY = 0);
	

	/// <summary>
	/// Gets the mouse position.
	/// </summary>
	/// <param name="offset">The offset.</param>
	/// <returns></returns>
	static SDL_Point getMousePosition(const SDL_Point & offset);

};
