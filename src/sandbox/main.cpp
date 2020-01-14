#include <iostream>
#include "tempComponent.h"

int main()
{
	std::shared_ptr<Core> defaultCore = Core::initialize();
	std::shared_ptr<Entity> defaultEntity = defaultCore->addEntity();
	std::shared_ptr<TempComponent> defaultComponent = defaultEntity->addComponent<TempComponent>();

	defaultCore->start();
	
  return 0;
};