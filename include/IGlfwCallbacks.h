#ifndef SIMPLEOBJVIEWER_IGLFWCALLBACKS_H
#define SIMPLEOBJVIEWER_IGLFWCALLBACKS_H

#include <GLFW/glfw3.h>

class IGlfwCallbacks{
public:
    virtual void cursorPositionCallback(GLFWwindow* window, double xpos, double ypos) = 0;

    virtual void mouseButtonCallback(GLFWwindow* window, int button, int action, int mods) = 0;

    virtual void mouseScrollCallback(GLFWwindow* window, double xoffset, double yoffset) = 0;

    virtual void windowSizeChangedCallback(GLFWwindow* window, int width, int height) = 0;
};

#endif //SIMPLEOBJVIEWER_IGLFWCALLBACKS_H
