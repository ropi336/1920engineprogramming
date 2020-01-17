#include "Core.h"
#include "Component.h"
#include "Entity.h"


///< Defining the window size
#define WINDOW_WIDTH 640
#define WINDOW_HEIGHT 480



Core::Core()
{
}

/**
* Core class destructor. Executes necessary commands to fully able
* to close the program showcase without causing errors.
*/


Core::~Core()
{
	context = NULL; ///< Clearing the context (which clears stored rendering data)
	entities.clear(); ///< Deleting entities

	SDL_DestroyWindow(window); ///< closes the display window
	SDL_Quit(); ///< shuts down SDL
}

/**
* This function initializes SDL and creates the window with the size that 
* was defined at the top of the window. Furthermore, it error checks just
* in case the window creation failed ( as that would mean the program
* cannot continue.) The context is also initialized for the storage of
* render data that the render classes require.
*/

std::shared_ptr<Core> Core::initialize()
{
	std::shared_ptr<Core> core = std::make_shared<Core>(); ///< Making the core a public member accessible by all classes
	if (SDL_Init(SDL_INIT_VIDEO) < 0)
	{
		throw std::exception();
	}

	core->window = SDL_CreateWindow("PASTA Engine Demo Showcase",
		SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED,
		WINDOW_WIDTH, WINDOW_HEIGHT, SDL_WINDOW_RESIZABLE | SDL_WINDOW_OPENGL);

	if (!SDL_GL_CreateContext(core->window))
	{
		throw std::exception();
	}

	if (glewInit() != GLEW_OK)  ///< Making sure that glew working!!
	{
		throw std::exception();
	}

	core->context = Context::initialize(); ///< Initializing context data container

	core->self = core;
	return core;
}

std::sr1::shared_ptr<Context> Core::getContext()
{
	return context;
}

/**
* Core LOOP function. This will execute at every frame that the program is running.
* This function loops through every entity, and updates one, before displaying one.
* This is done for every entity that is stored in the list.
*/

void Core::start()
{
	running = true; ///< Only runs the loop when it is allowed to do so

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

		for (std::list<std::shared_ptr<Entity>>::iterator it = entities.begin(); it != entities.end(); it++) ///< Looping through every entity
		{
			(*it)->tick(); ///< Updating every entity
		}

		glClearColor(0.10f, 0.15f, 0.25f, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
		for (std::list<std::shared_ptr<Entity>>::iterator it = entities.begin(); it != entities.end(); it++) ///< Looping through every entity
		{
			(*it)->display(); ///< Displaying every entity
		}

		SDL_GL_SwapWindow(window); ///< Updating the window with the new render data

	}

	
}



/**
* Initialize Entity before pushing to the list of entities
*/

std::shared_ptr<Entity> Core::addEntity()
{

	std::shared_ptr<Entity> tempEntity = std::make_shared<Entity>();
	tempEntity->self = tempEntity; ///< Vital for making sure that the entity is correctly stored in the object that creates it
	tempEntity->core = self; ///< Further storage in the core
	entities.push_back(tempEntity);
	return tempEntity;
}
