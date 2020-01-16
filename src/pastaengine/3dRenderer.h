#include "Component.h"
#include <rend/rend.h>
#include <sr1/memory>
#include <SDL2/SDL.h>
#include <string>

using namespace rend;

class  Renderer : public Component
{
public: 
	void onDisplay();

	void loadModel(std::string modlPath);
	void loadTexture(char const * texrPath);
private:
	
	std::string modelPath;
	char const * texturePath;
	


	std::sr1::shared_ptr<Context> context;

	std::sr1::shared_ptr<Shader> shader;

	std::sr1::shared_ptr<Mesh> shape;

	std::sr1::shared_ptr<Texture> texture;

	float angle = 0;
	void onInit();

};