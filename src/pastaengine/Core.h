#include <memory>
#include <list>

class Keyboard;
class Entity;
class Environment;

class Core {
private:
	bool running;
	std::shared_ptr<Keyboard> keybird;
	std::list<std::shared_ptr<Entity>> entities;
	std::shared_ptr<Environment> environment;

public:

	static std::shared_ptr<Core> initialize();
	void start();
	void stop();
	std::shared_ptr<Entity> addEntity();
};

