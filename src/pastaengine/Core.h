#include <memory>
#include <list>
#include "GL/glew.h"
#include <rend/rend.h>
#include <SDL2/SDL.h>
#include <sr1/memory>

using namespace rend;


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
	std::sr1::shared_ptr<Context> context;
	std::weak_ptr<Core> self;
public:
	 std::sr1::shared_ptr<Context> getContext();
	Core();
	~Core();
	static std::shared_ptr<Core> initialize();
	void start();
	void stop();
	std::shared_ptr<Entity> addEntity();
};

