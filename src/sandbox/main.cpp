#include <iostream>
#include "tempComponent.h"
#include "pastaengine/TriangleRenderer.h"
#include "pastaengine/3dRenderer.h"

int main()
{
	std::shared_ptr<Core> defaultCore = Core::initialize();
	std::shared_ptr<Entity> defaultEntity = defaultCore->addEntity();
	//std::shared_ptr<TriangleRenderer> triangleRenderer = defaultEntity->addComponent<TriangleRenderer>();
	std::shared_ptr<Renderer> renderer3D = defaultEntity->addComponent<Renderer>();
	//std::shared_ptr<TempComponent> defaultComponent = defaultEntity->addComponent<TempComponent>();
	defaultCore->start();
	
  return 0;
};