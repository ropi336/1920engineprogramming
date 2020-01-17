#include "Component.h"
#include "Entity.h"

/**
* These classes are empty due to the fact that the header file defines them to be
* virtual classes, meaning they can be filled out by the rest of the software.
*/


void Component::onInit()
{
}

void Component::onBegin()
{
}

void Component::onTick()
{
}

void Component::onDisplay()
{
}

/**
* Fetching entity data
*/

std::shared_ptr<Entity> Component::getEntity() ///< Fetching an entity to load the components onto
{
	return std::shared_ptr<Entity>();
}

std::shared_ptr<Core> Component::getCore()
{
	return entity.lock()->getCore();
}
