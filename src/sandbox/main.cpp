#include <iostream>
#include "pastaengine/pasta.h"
#include "pastaengine/3dRenderer.h"
#include "pastaengine/2dRenderer.h"

int main()
{
	std::shared_ptr<Core> defaultCore = Core::initialize();

	std::shared_ptr<Entity> squareEntity = defaultCore->addEntity();

	std::shared_ptr<Renderer2D> renderer2D = squareEntity->addComponent<Renderer2D>();

	std::shared_ptr<Entity> curuthers1 = defaultCore->addEntity();
	std::shared_ptr<Renderer3D> curthersRend1 = curuthers1->addComponent<Renderer3D>();
	curthersRend1->loadModel("../share/curuthers/curuthers.obj");
	curthersRend1->loadTexture("../share/curuthers/curuthers.png");
	curthersRend1->setPos(glm::vec3(0, 2, -20));

	std::shared_ptr<Entity> curuthers2 = defaultCore->addEntity();
	std::shared_ptr<Renderer3D> curuthersRend2 = curuthers2->addComponent<Renderer3D>();
	curuthersRend2->loadModel("../share/curuthers/curuthers.obj");
	curuthersRend2->loadTexture("../share/curuthers/curuthers2.png");
	curuthersRend2->setPos(glm::vec3(4, 2, -20));

	std::shared_ptr<Entity> curuthers3 = defaultCore->addEntity();
	std::shared_ptr<Renderer3D> curuthersRend3 = curuthers3->addComponent<Renderer3D>();
	curuthersRend3->loadModel("../share/curuthers/curuthers.obj");
	curuthersRend3->loadTexture("../share/curuthers/curuthers3.png");
	curuthersRend3->setPos(glm::vec3(-4, 2, -20));

	std::shared_ptr<Entity> curuthers4 = defaultCore->addEntity();
	std::shared_ptr<Renderer3D> curuthersRend4 = curuthers4->addComponent<Renderer3D>();
	curuthersRend4->loadModel("../share/curuthers/curuthers.obj");
	curuthersRend4->loadTexture("../share/curuthers/curuthers4.png");
	curuthersRend4->setPos(glm::vec3(0, -5, -20));
	
	defaultCore->start();
	
  return 0;
};