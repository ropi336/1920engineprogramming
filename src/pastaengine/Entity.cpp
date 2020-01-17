#include "Entity.h"
#include "Component.h"


/**
* Ticks through each component of a given entity
*/

void Entity::tick()
{
	for (std::list<std::shared_ptr<Component>>::iterator it = components.begin(); it != components.end(); it++) 
	{
		(*it)->onTick();
	}
}

/**
* Displays any displayable functions in the components of the given entity
*/

void Entity::display()
{
	for (std::list<std::shared_ptr<Component>>::iterator it = components.begin(); it != components.end(); it++)
	{
		(*it)->onDisplay();
	}
}

const std::shared_ptr<Core> Entity::getCore()
{
	return core.lock();
}
