cmake_minimum_required(VERSION 3.17)
project(simpleObjViewer)

set(CMAKE_CXX_STANDARD 11)

include_directories(include)

find_package(OpenGL REQUIRED)

find_package(glfw3 REQUIRED)

find_package(GLEW REQUIRED)

add_executable(simpleObjViewer main.cpp include/BasicWindow.h src/BasicWindow.cpp)

target_link_libraries(simpleObjViewer glfw OpenGL::GL GLEW::GLEW)