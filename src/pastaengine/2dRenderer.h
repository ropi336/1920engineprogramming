#include "Component.h"
#include <rend/rend.h>
#include <sr1/memory>
#include <SDL2/SDL.h>

using namespace rend;

/**
* Stores vital data required for rendering and displaying the 2D plane
*/

class  Renderer2D : public Component
{
public: 
	void onDisplay();


private:
	std::sr1::shared_ptr<Context> context; ///< Storing the required data for rendering
	std::sr1::shared_ptr<Shader> shader; ///<  storing the shader data
	std::sr1::shared_ptr<Mesh> shape; ///< storing the mesh data
	void onInit();

};