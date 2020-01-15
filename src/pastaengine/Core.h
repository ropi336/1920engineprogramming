#include <memory>
#include "stb_image.h"
#include <list>
#include "GL/glew.h"
#include <SDL2/SDL.h>

class Keyboard;
class Entity;
class Environment;
class Resources;

class Core {
private:
	SDL_Window *window;
	bool running;
	std::shared_ptr<Keyboard> keyboard;
	std::list<std::shared_ptr<Entity>> entities;
	std::shared_ptr<Environment> environment;
	std::shared_ptr<Resources> resources;

public:
	Core();

	static std::shared_ptr<Core> initialize();
	void start();
	void stop();
	std::shared_ptr<Entity> addEntity();
};

