#ifndef SIMPLEOBJVIEWER_UTILS_H
#define SIMPLEOBJVIEWER_UTILS_H

#include <GL/glew.h>
#include <string>

class Utils {
public:
    static bool checkOpenGLError();

    static void printProgramLog(int program);

    static void printShaderLog(GLuint shader);

    static std::string readShaderSource(const char *filePath);

    static GLuint createShaderProgram(const char *vertexShaderPath, const char *fragmentShaderPath);
};

#endif //SIMPLEOBJVIEWER_UTILS_H
