#pragma once
#include <list>
class AppObject;
class Component;
/// <summary>
/// The App class
/// </summary>
class SDLApp
{

public:
	/// <summary>
	/// Constructor of the class, just set the property run to true
	/// </summary>
	SDLApp();

	/// <summary>
	/// The destructor of the class
	/// </summary>
	~SDLApp();

	/// <summary>
	/// Initializes the dependencies of the app
	/// </summary>
	/// <returns>
	/// true if something went wrong, false every other case
	/// </returns>
	bool initDependencies();

	/// <summary>
	/// Init a sample scene
	/// </summary>
	void initScene();

	/// <summary>
	/// Close all the dependencies of the app
	/// </summary>
	void closeApp();

	/// <summary>
	/// For checking if the app is running
	/// </summary>
	/// <returns>
	/// True if running, false every other case
	/// </returns>
	bool isRunning();

	/// <summary>
	/// For setting the value running
	/// </summary>
	/// <param name="nValue">The new value</param>
	void setRunning(bool nValue);

	/// <summary>
	/// For handeling the input
	/// </summary>
	void handleInput();

	/// <summary>
	/// For update every object of the scene
	/// </summary>
	void tick();

	/// <summary>
	/// For render every object of the scene
	/// </summary>
	void render();

private:
	/// <summary>
	/// The application objects
	/// </summary>
	std::list<AppObject*> appObjects;
	Component * rectRender;

	/// <summary>
	/// The running value
	/// </summary>
	bool running_;

	/// <summary>
	/// For builiding a map 
	/// </summary>
	/// <param name="file">The file ubication</param>
	void buildMap(std::string file);

};