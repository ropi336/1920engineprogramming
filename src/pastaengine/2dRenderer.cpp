#include "3dRenderer.h"
#include "Core.h"


using namespace rend;

const char* src =
"#ifdef VERTEX                                 \n" \
"                                              \n" \
"attribute vec3 a_Position;                    \n" \
"attribute vec2 a_TexCoord;                    \n" \
"                                              \n" \
"uniform mat4 u_Projection;                    \n" \
"                                              \n" \
"varying vec2 v_TexCoord;                      \n" \
"                                              \n" \
"void main()                                   \n" \
"{                                             \n" \
"  vec3 pos = a_Position + vec3(0, 0, -5);     \n" \
"  gl_Position = u_Projection * vec4(pos, 1);  \n" \
"  v_TexCoord = a_TexCoord;                    \n" \
"}                                             \n" \
"                                              \n" \
"#endif                                        \n" \
"#ifdef FRAGMENT                               \n" \
"                                              \n" \
"varying vec2 v_TexCoord;                      \n" \
"                                              \n" \
"void main()                                   \n" \
"{                                             \n" \
"  gl_FragColor = vec4(v_TexCoord, 0, 1);      \n" \
"}                                             \n" \
"                                              \n" \
"#endif                                        \n";

const char* obj =
"v -1 1 0           \n" \
"v -1 -1 0          \n" \
"v 1 -1 0           \n" \
"v 1 1 0            \n" \
"                   \n" \
"vt 0 1             \n" \
"vt 0 0             \n" \
"vt 1 0             \n" \
"vt 1 1             \n" \
"                   \n" \
"f 1/1 2/2 3/3 4/4  \n" \
"                   \n";

void Renderer::onDisplay()
{
	std::sr1::shared_ptr<Context> context = Context::initialize();
	std::sr1::shared_ptr<Shader> shader = context->createShader();
	shader->parse(src);

	std::sr1::shared_ptr<Mesh> shape = context->createMesh();
	shape->parse(obj);

	bool running = true;
	SDL_Event e = { 0 };
	glClearColor(0.39f, 0.58f, 0.93f, 1.0f);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	shader->setUniform("u_Projection", perspective(radians(45.0f), 1.0f, 0.1f, 100.0f));
	shader->setMesh(shape);
	shader->render();
}

void Renderer::onInit()
{

}
