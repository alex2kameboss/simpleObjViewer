#include <RenderWindowCallbacksManager.h>

#include <memory>

RenderWindowCallbacksManager::RenderWindowCallbacksManager() {}

RenderWindowCallbacksManager *RenderWindowCallbacksManager::getInstance() {
    static RenderWindowCallbacksManager* instance = nullptr;

    if(!instance)
        instance = new RenderWindowCallbacksManager();

    return instance;
}

void RenderWindowCallbacksManager::setCallbacksHandler(IGlfwCallbacks *handler) {
    callbacksHandler = handler;
}

IGlfwCallbacks* RenderWindowCallbacksManager::getCallbacksHandler() {
    return callbacksHandler;
}

void RenderWindowCallbacksManager::cursorPositionCallback(GLFWwindow *window, double xPos, double yPos) {
    RenderWindowCallbacksManager::getInstance()->getCallbacksHandler()->cursorPositionCallback(window, xPos, yPos);
}

void RenderWindowCallbacksManager::mouseButtonCallback(GLFWwindow *window, int button, int action, int mods) {
    RenderWindowCallbacksManager::getInstance()->getCallbacksHandler()->mouseButtonCallback(window, button, action, mods);
}

void RenderWindowCallbacksManager::mouseScrollCallback(GLFWwindow *window, double xOffset, double yOffset) {
    RenderWindowCallbacksManager::getInstance()->getCallbacksHandler()->mouseScrollCallback(window, xOffset, yOffset);
}

void RenderWindowCallbacksManager::windowSizeChangedCallback(GLFWwindow *window, int width, int height) {
    RenderWindowCallbacksManager::getInstance()->getCallbacksHandler()->windowSizeChangedCallback(window, width, height);
}