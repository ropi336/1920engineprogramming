cmake_minimum_required(VERSION 2.6)
project(ROPI)

add_library(pastaengine
 src/pastaengine/pasta.cpp
 src/pastaengine/Core.cpp
 src/pastaengine/Core.h
 src/pastaengine/pasta.h
)
target_link_libraries(pastaengine SDL2 opengl32 glew32)

add_executable(sandbox
 src/sandbox/main.cpp
)