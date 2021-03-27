#include <Utils.h>

#include <iostream>
#include <fstream>

void Utils::printShaderLog(GLuint shader){
    int len = 0;
    int chWriten = 0;
    char* log;
    glGetShaderiv(shader, GL_INFO_LOG_LENGTH, &len);
    if(len > 0){
        log = new char[len];
        glGetShaderInfoLog(shader, len, &chWriten, log);
        std::cout << "Shader info log: "<< log << std::endl;
        delete [] log;
    }
}

void Utils::printProgramLog(int program){
    int len = 0;
    int chWriten = 0;
    char* log;
    glGetProgramiv(program, GL_INFO_LOG_LENGTH, &len);
    if(len > 0){
        log = new char[len];
        glGetProgramInfoLog(program, len, &chWriten, log);
        std::cout << "Program info log: " << log << std::endl;
        delete [] log;
    }
}

bool Utils::checkOpenGLError(){
    bool foundError = false;
    int glErr = glGetError();
    while (glErr != GL_NO_ERROR){
        std::cout << "glError: " << glErr << std::endl;
        foundError = true;
        glErr = glGetError();
    }
    return foundError;
}

std::string Utils::readShaderSource(const char *filePath){
    std::string content;
    std::ifstream fileStream(filePath, std::ios::in);
    std::string line;

    while (!fileStream.eof()){
        getline(fileStream, line);
        content.append(line+'\n');
    }
    fileStream.close();

    return content;
}

GLuint Utils::createShaderProgram(const char *vertexShaderPath, const char *fragmentShaderPath) {
    GLint vertCompiled;
    GLint fragCompiled;
    GLint linked;

    std::string vertShaderStr = readShaderSource(vertexShaderPath);
    std::string fragShaderStr = readShaderSource(fragmentShaderPath);

    const char* vshaderSource = vertShaderStr.c_str();
    const char* fshaderSource = fragShaderStr.c_str();

    // create shader
    GLuint vShader = glCreateShader(GL_VERTEX_SHADER);
    GLuint fShader = glCreateShader(GL_FRAGMENT_SHADER);

    // generate shaders programs
    glShaderSource(vShader, 1, &vshaderSource, NULL);
    glShaderSource(fShader, 1, &fshaderSource, NULL);

    // catch error while compiling shaders
    glCompileShader(vShader);
    checkOpenGLError();
    glGetShaderiv(vShader, GL_COMPILE_STATUS, &vertCompiled);
    if(vertCompiled != 1){
        std::cout << "Vertex compilation failed" << std::endl;
        printShaderLog(vShader);
    }

    glCompileShader(fShader);
    checkOpenGLError();
    glGetShaderiv(fShader, GL_COMPILE_STATUS, &fragCompiled);
    if(fragCompiled != 1){
        std::cout << "Fragment compilation failed" << std::endl;
        printShaderLog(fShader);
    }

    // create opengl program
    GLuint vfProgram = glCreateProgram();

    // catch errors while linking shaders
    // attach shader to program
    glAttachShader(vfProgram, vShader);
    glAttachShader(vfProgram, fShader);
    // check if the opengl and glsl are compatible
    glLinkProgram(vfProgram);

    checkOpenGLError();
    glGetProgramiv(vfProgram, GL_LINK_STATUS, &linked);
    if(linked != 1){
        std::cout << "Linked failed" << std::endl;
        printProgramLog(vfProgram);
    }

    return vfProgram;
}
