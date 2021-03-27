#ifndef SIMPLEOBJVIEWER_RENDERWINDOWCALLBACKSMANAGER_H
#define SIMPLEOBJVIEWER_RENDERWINDOWCALLBACKSMANAGER_H

#include <IGlfwCallbacks.h>

// singleton class
class RenderWindowCallbacksManager{
private:
    IGlfwCallbacks* callbacksHandler;

    RenderWindowCallbacksManager();

public:
    static RenderWindowCallbacksManager* getInstance();

    void setCallbacksHandler(IGlfwCallbacks* handler);

    IGlfwCallbacks * getCallbacksHandler();

    static void cursorPositionCallback(GLFWwindow* window, double xPos, double yPos);

    static void mouseButtonCallback(GLFWwindow* window, int button, int action, int mods);

    static void mouseScrollCallback(GLFWwindow* window, double xOffset, double yOffset);

    static void windowSizeChangedCallback(GLFWwindow* window, int width, int height);
};

#endif //SIMPLEOBJVIEWER_RENDERWINDOWCALLBACKSMANAGER_H
