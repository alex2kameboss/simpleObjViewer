#include <BasicWindow.h>

#include <iostream>

BasicWindow::BasicWindow(const std::string &_windowTitle)
    : windowTitle(_windowTitle) { }

bool BasicWindow::init() {
    // init glfw
    if(!glfwInit()){
        std::cout << "Failed to init glfw" << std::endl;
        return false;
    }

    // OpenGL 4.3
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);

    // create a window, 600x600
    window = glfwCreateWindow(600, 600, windowTitle.c_str(), nullptr, nullptr);

    if(window == nullptr){
        std::cout << "Failed to create glfw window" << std::endl;
        return -1;
    }

    // bind opengl to this window
    glfwMakeContextCurrent(window);

    // init glew
    auto status = glewInit();
    if(status != GLEW_OK){
        std::cout << "Failed to init glew" << std::endl;
        std::cout << glewGetErrorString(status) << std::endl;
        return false;
    }

    glfwSwapInterval(1);

    return true;
}

void BasicWindow::run() {
    while (!glfwWindowShouldClose(window)){
        // call display function
        display();

        // get show buffer for window
        glfwSwapBuffers(window);
        // draw buffer
        glfwPollEvents();
    }

    // cleanup
    glfwDestroyWindow(window);
    glfwTerminate();
}

void BasicWindow::display() {
    //set background color
    glClearColor(0.878, 1.0, 1.0, 1.0);

    // void glClear(GLbitfield mask)
    // GL_COLOR_BUFFERE_BIT : references the color buffer
    // glClear() : clears all of color buffers that OpenGL has
    glClear(GL_COLOR_BUFFER_BIT);
}
