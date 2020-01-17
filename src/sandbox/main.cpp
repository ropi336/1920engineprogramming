#include <iostream>
#include "pastaengine/pasta.h"
#include "pastaengine/3dRenderer.h"
#include "pastaengine/2dRenderer.h"

int main()
{
/**
* Core - Stores data of essential entities and models, updates, renders them as required
* Currently, it's done every single frame
*/

	std::shared_ptr<Core> defaultCore = Core::initialize(); ///< Initialized core

	std::shared_ptr<Entity> squareEntity = defaultCore->addEntity();

	std::shared_ptr<Renderer2D> renderer2D = squareEntity->addComponent<Renderer2D>(); ///< Attaching the 2D rendering component

/**
* The section below initializes an entity, then attaches an object instance renderer component to load
* and display the model and texture, and also giving it a vec3 position
* This section is repeated with different entities, models, textures, vec3 positions
* In order to render several different models onto the screen.
*/

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

	std::shared_ptr<Entity> curuthersBlack = defaultCore->addEntity();
	std::shared_ptr<Renderer3D> curuthersRendBlack = curuthersBlack->addComponent<Renderer3D>();
	curuthersRendBlack->loadModel("../share/curuthers/curuthers.obj");
	curuthersRendBlack->loadTexture("../share/curuthers/curuthersblack.png");
	curuthersRendBlack->setPos(glm::vec3(0, 10, -25));
	
	defaultCore->start(); ///< Looping core update function
	
  return 0;
};