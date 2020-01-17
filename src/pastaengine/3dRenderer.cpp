#include "3dRenderer.h"
#include "Core.h"

#define STB_IMAGE_IMPLEMENTATION
#include "stb_image.h"

#include <iostream>
#include <fstream>

using namespace rend;


/**
* local Vertex Shader
*/
const char* src =
"#ifdef VERTEX                                 \n" \
"                                              \n" \
"attribute vec3 a_Position;                    \n" \
"attribute vec2 a_TexCoord;                    \n" \
"attribute vec3 a_Normal;                      \n" \
"                                              \n" \
"uniform mat4 u_Projection;                    \n" \
"uniform mat4 u_Model;                         \n" \
"                                              \n" \
"varying vec3 v_Normal;                        \n" \
"varying vec2 v_TexCoord;                      \n" \
"                                              \n" \
"void main()                                   \n" \
"{                                             \n" \
"  gl_Position = u_Projection *                \n" \
"    u_Model * vec4(a_Position, 1);            \n" \
"                                              \n" \
"  v_Normal = a_Normal;                        \n" \
"  v_TexCoord = a_TexCoord;                    \n" \
"}                                             \n" \
"                                              \n" \
"#endif                                        \n" \
"#ifdef FRAGMENT                               \n" \
"                                              \n" \
"uniform sampler2D u_Texture;                  \n" \
"                                              \n" \
"varying vec3 v_Normal;                        \n" \
"varying vec2 v_TexCoord;                      \n" \
"                                              \n" \
"void main()                                   \n" \
"{                                             \n" \
"  gl_FragColor = texture2D(u_Texture, v_TexCoord);      \n" \
"  if(gl_FragColor.x == 9) gl_FragColor.x = v_Normal.x;  \n" \
"}                                             \n" \
"                                              \n" \
"#endif                                        \n";



/**
* This function runs when display is called by the Core
*/
void Renderer3D::onDisplay()
{

	angle += 3.0f; ///< Initiating spin


/**
* This information is required to be given to the shader to render the object. 
* A projection is also created so that the model shows up on the window
*/
	shader->setUniform("u_Projection", perspective(radians(65.0f), 1.0f, 0.1f, 100.0f));///< Creating a projection matrix (because there is no camera class)
	shader->setUniform("u_Model",
		translate(glm::mat4(1.0f), modelPos) *
		rotate(glm::mat4(1.0f), radians(angle), vec3(0, 1, 0))
	);

	shader->setMesh(shape); ///< Passing the newly acquired mesh to the shader
	shader->render(); ///< Passing the shaded mesh to the renderer to be displayed on screen
}

/**
* This is for retrieving the model position from main in order to allow the program to correctly render the mesh in the given place.
*/
void Renderer3D::setPos(vec3 modPos)
{
	modelPos = modPos; ///< Storing the retrieved positional vector in the class object
}

/**
* The function below retrieves the required context from the core
* Then, the model path is retrieved from the game showcase, so it can then parse the obj file and prepare the model for shading 
*/

void Renderer3D::loadModel(std::string  modlPath)
{
	context = getCore()->getContext(); ///< Core context
	shader = context->createShader();  ///< preparing the shader
	shader->parse(src);  ///<  Parsing the internal fragment shader code 

	shape = context->createMesh(); ///< Storing the created mesh in the shape variable

	std::ifstream f(modlPath); ///< Fetching the model from the provided path that is provided by the game showcase

		if (!f.is_open())
		{
			throw Exception("Failed to open model");///< Crashed the program in case the model isn't found
		}

		std::string obj;
		std::string line;

		while (!f.eof())
		{
			std::getline(f, line);
			obj += line + "\n";
		}

		shape->parse(obj);
}

/**
* This function is for loading a texture to render onto the loaded object.
*/

void Renderer3D::loadTexture(char const * texrPath)
{
	texture = context->createTexture(); ///<  Storing the texture in context
	int w = 0; ///<  width
	int h = 0; ///< height
	int bpp = 0; 
	unsigned char *data = stbi_load(texrPath,&w, &h, &bpp, 3); ///< Loading and parsing image data. File location, then width, then height

	if (!data)
	{
		throw Exception("Failed to open image");
	}

	texture->setSize(w, h);
/**
* Runs through every pixel of the image to correctly change every pixel that is drawn to the model later.
*/

	for (int y = 0; y < h; y++)
	{
		for (int x = 0; x < w; x++)
		{
			int r = y * w * 3 + x * 3;

			texture->setPixel(x, y, vec3( ///< sets the colour of the pixel to prepare rendering of the diffuse
				data[r] / 255.0f,
				data[r + 1] / 255.0f,
				data[r + 2] / 255.0f));
		}
	}
	stbi_image_free(data);
	shape->setTexture("u_Texture", texture);
}



void Renderer3D::onInit()
{

}