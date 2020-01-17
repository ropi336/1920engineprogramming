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

	void loadModel(std::string modlPath);
	void loadTexture(char const * texrPath);
	void setPos(glm::vec3 modPos);
private:
	glm::vec3 modelPos;

	std::sr1::shared_ptr<Context> context;

	std::sr1::shared_ptr<Shader> shader;

	std::sr1::shared_ptr<Mesh> shape;

	std::sr1::shared_ptr<Texture> texture;

	float angle = 0;
	void onInit();

};