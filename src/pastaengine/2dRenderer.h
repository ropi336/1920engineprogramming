#include "Component.h"
#include <rend/rend.h>
#include <sr1/memory>
#include <SDL2/SDL.h>



class  Renderer : public Component
{
public: 
	void onDisplay();

private:
	void onInit();

};