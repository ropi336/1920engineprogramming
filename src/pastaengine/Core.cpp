#include "Core.h"

std::shared_ptr<Core> Core::initialize()
{
	std::shared_ptr<Core> core = std::make_shared<Core>(Core::Core());
	return core;
}
