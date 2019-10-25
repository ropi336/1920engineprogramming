cmake_minimum_required(VERSION 2.6)
project(ROPI)

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
 src/pastaengine/Screen.h


)
target_link_libraries(pastaengine SDL2 opengl32 glew32)

add_executable(sandbox
 src/sandbox/main.cpp
)