#include <memory>
#include <list>
#include "GL/glew.h"
#include <rend/rend.h>
#include <SDL2/SDL.h>
#include <sr1/memory>

using namespace rend;
class Entity;

class Core {
private:
	SDL_Window *window;
	bool running;
	std::list<std::shared_ptr<Entity>> entities;
	std::sr1::shared_ptr<Context> context;
	std::weak_ptr<Core> self;
public:
	 std::sr1::shared_ptr<Context> getContext(); ///< Storing data for any entities/components
	Core(); ///< constructor
	~Core(); ///< destructor
	static std::shared_ptr<Core> initialize();
	void start();
	std::shared_ptr<Entity> addEntity();
};

