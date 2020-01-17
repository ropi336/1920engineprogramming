cmake_minimum_required(VERSION 2.6)
project(ROPI)

include_directories(
src
)

add_library(pastaengine
 src/pastaengine/pasta.cpp
 src/pastaengine/Core.cpp
 src/pastaengine/Component.cpp
 src/pastaengine/Entity.cpp
 src/pastaengine/3dRenderer.cpp
 src/pastaengine/2dRenderer.cpp
 src/pastaengine/Core.h
 src/pastaengine/pasta.h
 src/pastaengine/Component.h
 src/pastaengine/Entity.h
 src/pastaengine/3dRenderer.h
 src/pastaengine/2dRenderer.h
 src/pastaengine/stb_image.h)

add_library(rend
src/rend/Exception.cpp
src/rend/Context.cpp
src/rend/Texture.cpp
src/rend/RenderTexture.cpp
src/rend/Shader.cpp
src/rend/Buffer.cpp
src/rend/Mesh.cpp
src/rend/Util.cpp
)

if (MSVC)
	target_link_libraries(rend glew32 opengl32)
else()
	target_link_libraries(rend GLEW GL)
endif()

target_link_libraries(pastaengine rend SDL2)

add_executable(sandbox
 src/sandbox/main.cpp)

target_link_libraries(sandbox
 pastaengine)