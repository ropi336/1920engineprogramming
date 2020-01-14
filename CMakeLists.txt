cmake_minimum_required(VERSION 2.6)
project(ROPI)

include_directories(
src
)

add_library(pastaengine
 src/pastaengine/pasta.cpp
 src/pastaengine/Core.cpp
 src/pastaengine/Component.cpp
 src/pastaengine/Keyboard.cpp
 src/pastaengine/Environment.cpp
 src/pastaengine/Entity.cpp
 src/pastaengine/Screen.cpp
 src/pastaengine/Core.h
 src/pastaengine/pasta.h
 src/pastaengine/Component.h
 src/pastaengine/Keyboard.h
 src/pastaengine/Environment.h
 src/pastaengine/Entity.h
 src/pastaengine/Screen.h)

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
 src/sandbox/main.cpp
 src/sandbox/tempComponent.h
 src/sandbox/tempComponent.cpp)

target_link_libraries(sandbox
 pastaengine)