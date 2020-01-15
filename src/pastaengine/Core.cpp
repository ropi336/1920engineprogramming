#include "Core.h"
#include "Component.h"
#include "Entity.h"

#define WINDOW_WIDTH 640
#define WINDOW_HEIGHT 480

Core::Core()
{
}

std::shared_ptr<Core> Core::initialize()
{
	std::shared_ptr<Core> core = std::make_shared<Core>();
	if (SDL_Init(SDL_INIT_VIDEO) < 0)
	{
		throw std::exception();
	}

	core->window = SDL_CreateWindow("PASTA Engine",
		SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED,
		WINDOW_WIDTH, WINDOW_HEIGHT, SDL_WINDOW_RESIZABLE | SDL_WINDOW_OPENGL);

	if (!SDL_GL_CreateContext(core->window))
	{
		throw std::exception();
	}

	if (glewInit() != GLEW_OK)
	{
		throw std::exception();
	}



	return core;
}

void Core::start()
{
	bool running = true;

	while (running)
	{
		SDL_Event event = { 0 };

		while (SDL_PollEvent(&event))
		{
			if (event.type == SDL_QUIT)
			{
				running = false;
			}
		}

		for (std::list<std::shared_ptr<Entity>>::iterator it = entities.begin(); it != entities.end(); it++)
		{
			(*it)->tick();

		}
		for (std::list<std::shared_ptr<Entity>>::iterator it = entities.begin(); it != entities.end(); it++)
		{
			(*it)->display();
		}

		SDL_GL_SwapWindow(window);

	}

	SDL_DestroyWindow(window);
	SDL_Quit();
}

void Core::stop()
{
}

std::shared_ptr<Entity> Core::addEntity()
{
	//initialize 3D Entity before pushing to the list of entities
	std::shared_ptr<Entity> tempEntity = std::make_shared<Entity>();
	tempEntity->self = tempEntity;
	entities.push_back(tempEntity);
	return tempEntity;
}
