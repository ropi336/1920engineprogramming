#include "2dRenderer.h"
#include "Core.h"

/**
* The Vertex Data that provides the values for rendering the square in the correct position, size and colour
*/

const char* src2D =
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
"  vec3 pos = a_Position + vec3(0, -3, -10);     \n" \
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

void Renderer2D::onDisplay()
{
	shader->render();
}

void Renderer2D::onInit()
{
	context = getCore()->getContext();  ///<  Preparing the context for the storage of 
	shader = context->createShader(); ///< Storing the shader
	shader->parse(src2D); ///< Parsing the vertex file defined at the top of the class 
	shape = context->createMesh(); ///< storing the mesh 
	shape->parse(obj); ///< parsing the vertex data to define the rectangle
	shader->setUniform("u_Projection", perspective(radians(45.0f), 1.0f, 0.1f, 100.0f)); ///< creating a projection matrix to make the object viewable
	shader->setMesh(shape); ///< rendering the shape
}
