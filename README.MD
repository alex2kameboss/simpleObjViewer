# Simple OBJ Viewer

A simple implementation for a OBJ viewer with **C++11** and **OpenGL 4.3**

Can render files that have vertices coordinates,  vertices normals and vertices texture mapping

## Getting Started

These instructions will get you a copy of the project up and running on your local machine for development and testing purposes. See deployment for notes on how to deploy the project on a live system.

### Prerequisites

- [GLFW](https://www.glfw.org/)
- [OpenGL](https://www.khronos.org/opengl/wiki/Getting_Started)
- [GLEW](http://glew.sourceforge.net/)
- [GLM](https://github.com/g-truc/glm)
- A computer which support OpenGL 4.3 

#### For Ubuntu

```
sudo apt update
sudo apt install cmake
sudo apt-get update
sudo apt-get install libglu1-mesa-dev freeglut3-dev mesa-common-dev
sudo apt-get install libglfw3 libglfw3-dev
sudo apt-get install libglew-dev
sudo apt install libglm-dev
```

### Compiling

Build and run

* Ubuntu

```
mkdir build
cd build
cmake ../
make
./simpleObjViewer
```

## Features

+ Zoom, with Scroll Wheel
+ Rotate the object, with Right Click and mouse move
+ Pan the object, with Left Click and mouse move
+ Press Scroll Wheel will place the object in original place adn position
+ View window is resizeable
+ Accept OBJ wit untriangulated faces

## Built With

- [GLFW](https://www.glfw.org/)
- [OpenGL](https://www.khronos.org/opengl/wiki/Getting_Started)
- [GLEW](http://glew.sourceforge.net/)
- [GLM](https://github.com/g-truc/glm)

## Authors

* **Puscasu Alexandru** - [alex2kameboss](https://github.com/alex2kameboss)

## License

This project is licensed under the MIT License.
