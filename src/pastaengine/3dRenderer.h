#include "Component.h"
#include <rend/rend.h>
#include <sr1/memory>
#include <SDL2/SDL.h>
#include <string>

using namespace rend;

class  Renderer3D : public Component
{
public: 
	void onDisplay();

	void loadModel(std::string modlPath); ///< fetching file that is required to render a model
	void loadTexture(char const * texrPath); ///< fetching file that is required to attach a texture to the model
	void setPos(glm::vec3 modPos); ///< fetching the vec3 position of the model so they are not all in the same place
private:
	glm::vec3 modelPos;

	std::sr1::shared_ptr<Context> context; ///< storing all essential data

	std::sr1::shared_ptr<Shader> shader; ///< storing shader fx 

	std::sr1::shared_ptr<Mesh> shape; ///< storing parsed 3D model data

	std::sr1::shared_ptr<Texture> texture; ///< Storing PNG image file

	float angle = 0;
	void onInit();

};