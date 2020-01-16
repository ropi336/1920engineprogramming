#include <iostream>
#include "tempComponent.h"
#include "pastaengine/TriangleRenderer.h"
#include "pastaengine/3dRenderer.h"

int main()
{
	std::shared_ptr<Core> defaultCore = Core::initialize();
	std::shared_ptr<Entity> curuthers1 = defaultCore->addEntity();
	std::shared_ptr<Renderer> curthersRend1 = curuthers1->addComponent<Renderer>();
	curthersRend1->loadModel("../share/curuthers/curuthers.obj");
	curthersRend1->loadTexture("../share/curuthers/curuthers.png");
	curthersRend1->getPos(glm::vec3(0, -1, -10));

	std::shared_ptr<Entity> curuthers2 = defaultCore->addEntity();
	std::shared_ptr<Renderer> curuthersRend2 = curuthers2->addComponent<Renderer>();
	curuthersRend2->loadModel("../share/curuthers/curuthers.obj");
	curuthersRend2->loadTexture("../share/curuthers/curuthers.png");
	curuthersRend2->getPos(glm::vec3(3, -2, -10));
	//std::shared_ptr<TriangleRenderer> triangleRenderer = defaultEntity->addComponent<TriangleRenderer>();
	//std::shared_ptr<TempComponent> defaultComponent = defaultEntity->addComponent<TempComponent>();
	defaultCore->start();
	
  return 0;
};