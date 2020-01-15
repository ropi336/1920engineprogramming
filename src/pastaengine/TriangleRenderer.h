#include "stb_image.h"
#include <GL/glew.h>
#include <SDL2/SDL.h>
#include "Component.h"

class TriangleRenderer : public Component
{
private:
	GLuint programId;
	GLuint vboId;
	GLuint vaoId;
	void onDisplay();
public:
	void onInit();
	~TriangleRenderer();
};