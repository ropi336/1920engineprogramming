#include "3dRenderer.h"
#include "Core.h"

#define STB_IMAGE_IMPLEMENTATION
#include "stb_image.h"

#include <iostream>
#include <fstream>

using namespace rend;

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




void Renderer::onDisplay()
{
	angle += 3.0f;

	glClearColor(0.10f, 0.15f, 0.25f, 1.0f);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	shader->setUniform("u_Projection", perspective(radians(65.0f), 1.0f, 0.1f, 100.0f));

	shader->setUniform("u_Model",
		translate(glm::mat4(1.0f), modelPos) *
		rotate(glm::mat4(1.0f), radians(angle), vec3(0, 1, 0))
	);

	shader->setMesh(shape);
	shader->render();
}

void Renderer::getPos(vec3 modPos)
{
	modelPos = modPos;
}

void Renderer::loadModel(std::string  modlPath)
{
	modelPath = modlPath;
	context = Context::initialize();
	shader = context->createShader();
	shader->parse(src);

	shape = context->createMesh();

		std::ifstream f(modlPath);

		if (!f.is_open())
		{
			throw Exception("Failed to open model");
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

void Renderer::loadTexture(char const * texrPath)
{
	texturePath = texrPath;
	texture = context->createTexture();
		int w = 0;
		int h = 0;
		int bpp = 0;
		unsigned char *data = stbi_load(texrPath,
			&w, &h, &bpp, 3);

		if (!data)
		{
			throw Exception("Failed to open image");
		}

		texture->setSize(w, h);

		for (int y = 0; y < h; y++)
		{
			for (int x = 0; x < w; x++)
			{
				int r = y * w * 3 + x * 3;

				texture->setPixel(x, y, vec3(
					data[r] / 255.0f,
					data[r + 1] / 255.0f,
					data[r + 2] / 255.0f));
			}
		}
		stbi_image_free(data);
		shape->setTexture("u_Texture", texture);
}



void Renderer::onInit()
{
}