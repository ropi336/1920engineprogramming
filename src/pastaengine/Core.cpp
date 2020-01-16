#include "Core.h"
#include "Component.h"
#include "Entity.h"

#define WINDOW_WIDTH 640
#define WINDOW_HEIGHT 480



Core::Core()
{
}

Core::~Core()
{
	context = NULL;
	entities.clear();

	SDL_DestroyWindow(window);
	SDL_Quit();
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

	core->context = Context::initialize();

	core->self = core;
	return core;
}

std::sr1::shared_ptr<Context> Core::getContext()
{
	return context;
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

		glClearColor(0.10f, 0.15f, 0.25f, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
		for (std::list<std::shared_ptr<Entity>>::iterator it = entities.begin(); it != entities.end(); it++)
		{
			(*it)->display();
		}

		SDL_GL_SwapWindow(window);

	}

	
}

void Core::stop()
{
}

std::shared_ptr<Entity> Core::addEntity()
{
	//initialize 3D Entity before pushing to the list of entities
	std::shared_ptr<Entity> tempEntity = std::make_shared<Entity>();
	tempEntity->self = tempEntity;
	tempEntity->core = self;
	entities.push_back(tempEntity);
	return tempEntity;
}
