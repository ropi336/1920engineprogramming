cmake_minimum_required(VERSION 2.6)
project(ROPI)

add_library(pastaengine
 src/pastaengine/dummy.cpp
)
target_link_libraries(pastaengine SDL2 opengl32 glew32)

add_executable(sandbox
 src/sandbox/main.cpp
)