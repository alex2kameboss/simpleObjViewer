#ifndef SIMPLEOBJVIEWER_BASICWINDOW_H
#define SIMPLEOBJVIEWER_BASICWINDOW_H

// glfw includes, with openGL
#include <GL/glew.h>
#include <GLFW/glfw3.h>

#include <string>

class BasicWindow{
protected:
    std::string windowTitle;
    GLFWwindow* window;

    virtual void display();

public:
    BasicWindow(const std::string &_windowTitle);

    virtual bool init();

    virtual void run();
};

#endif //SIMPLEOBJVIEWER_BASICWINDOW_H
