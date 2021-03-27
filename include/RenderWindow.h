#ifndef SIMPLEOBJVIEWER_RENDERWINDOW_H
#define SIMPLEOBJVIEWER_RENDERWINDOW_H

#include <BasicWindow.h>
#include <IGlfwCallbacks.h>
#include <ObjModel.h>

#include <glm/glm.hpp>

class RenderWindow : public virtual IGlfwCallbacks, public virtual BasicWindow{
protected:
    static const int numVAOs = 1;   // one array for one object
    static const int numVBOs = 3;   // vertices, vertices normals and vertices texture map

    GLuint vao[numVAOs];
    GLuint vbo[numVBOs];

    //shader data
    const char* vertexShaderPath = "../shaders/vertexShader.glsl";
    const char* fragmentShaderPath = "../shaders/fragmentShader.glsl";
    GLuint renderingProgram;
    GLuint mvpMatrixLocation, mMatrixLocation, vMatrixLocation, mInvTrMatrixLocation;

    //object location
    glm::vec3 objectPosition;
    glm::vec3 cameraPosition;

    //matrices
    glm::mat4 vMatrix, mMatrix, mvpMatrix, pMatrix, mInvTrMatrix;

    //light properties
    glm::vec3 lightPosition;
    glm::vec4 lightColor;
    GLuint lightPositionLocation, lightColorPosition;

    // number of triangles to draw
    int trianglesNumber = 0;

    //mouse variables
    bool isPanOn = false;
    bool isRotateOn = false;
    float xAxisAngle, yAxisAngle;
    glm::vec3 mouseDisplacement;
    glm::vec<2, double> oldMousePosition;
    const float R = 100;

    void fillBuffers(const ObjModel& objModel);

    void display() override;

public:
    RenderWindow();

    bool init() override;

    void run(const ObjModel& objModel);

    void cursorPositionCallback(GLFWwindow *window, double xpos, double ypos) override;

    void mouseButtonCallback(GLFWwindow *window, int button, int action, int mods) override;

    void mouseScrollCallback(GLFWwindow *window, double xoffset, double yoffset) override;

    void windowSizeChangedCallback(GLFWwindow *window, int width, int height) override;

private:
    using BasicWindow::run;
};

#endif //SIMPLEOBJVIEWER_RENDERWINDOW_H
