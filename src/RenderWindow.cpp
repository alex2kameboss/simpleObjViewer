#include <RenderWindow.h>

#include <Utils.h>

#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

RenderWindow::RenderWindow()
    : BasicWindow("Simple OBJ Viewer")
    , objectPosition(0, 0, 0)
    , cameraPosition(0, 0, 8)
    , lightPosition(1, 1, 8)
    , lightColor(1, 1, 1, 1){ }

bool RenderWindow::init() {
    bool statusValue = BasicWindow::init();

    // create rendering program
    renderingProgram = Utils::createShaderProgram(vertexShaderPath,
                                                  fragmentShaderPath);

    // find this uniform data location
    mvpMatrixLocation = glGetUniformLocation(renderingProgram, "mvpMatrix");
    mMatrixLocation = glGetUniformLocation(renderingProgram, "mMatrix");
    vMatrixLocation = glGetUniformLocation(renderingProgram, "vMatrix");
    lightPositionLocation = glGetUniformLocation(renderingProgram, "lightPosition");
    lightColorPosition = glGetUniformLocation(renderingProgram, "lightColor");
    mInvTrMatrixLocation = glGetUniformLocation(renderingProgram, "mInvTrMatrix");

    // build perspective matrix
    // window dimension
    int height, width;
    glfwGetFramebufferSize(window, &width, &height);
    float aspect = (float)width/(float)height;
    pMatrix = glm::perspective(1.0472f, aspect, 0.1f, 1000.0f);

    // build view matrix
    vMatrix = glm::translate(glm::mat4(1), -cameraPosition);

    glUseProgram(renderingProgram);

    // set opengl drawing properties
    glEnable(GL_DEPTH_TEST);
    glDepthFunc(GL_LEQUAL);
    glEnable(GL_CULL_FACE);
    glFrontFace(GL_CCW);

    return statusValue;
}

void RenderWindow::fillBuffers(const ObjModel &objModel) {
    glGenVertexArrays(numVAOs, vao);    // create array object
    glBindVertexArray(vao[0]);          // bind the created array
    glGenBuffers(numVBOs, vbo);         // create buffers for object

    // load vertices on gpu
    glBindBuffer(GL_ARRAY_BUFFER, vbo[0]);
    glBufferData(GL_ARRAY_BUFFER,
                 sizeof(float) * objModel.getVertices().size(),
                 objModel.getVertices().data(),
                 GL_STATIC_DRAW);

    // load uvs on gpu
    glBindBuffer(GL_ARRAY_BUFFER, vbo[1]);
    glBufferData(GL_ARRAY_BUFFER,
                 sizeof(float) * objModel.getUvs().size(),
                 objModel.getUvs().data(),
                 GL_STATIC_DRAW);

    // load normals on gpu
    glBindBuffer(GL_ARRAY_BUFFER, vbo[2]);
    glBufferData(GL_ARRAY_BUFFER,
                 sizeof(float) * objModel.getNormals().size(),
                 objModel.getNormals().data(),
                 GL_STATIC_DRAW);
}

void RenderWindow::run(const ObjModel &objModel) {
    fillBuffers(objModel);

    // set number of triangles
    trianglesNumber = objModel.getVertices().size() / 3;

    BasicWindow::run();
}

void RenderWindow::display() {
    glClear(GL_DEPTH_BUFFER_BIT);
    glClear(GL_COLOR_BUFFER_BIT);

    //set background color
    glClearColor(0.878, 1.0, 1.0, 1.0);

    //build model matrix
    mMatrix = glm::translate(glm::mat4(1), objectPosition);

    mInvTrMatrix = glm::transpose(glm::inverse(mMatrix));

    //build mvpMatrix
    mvpMatrix = pMatrix * vMatrix * mMatrix;

    //send data to GPU
    glUniformMatrix4fv(mvpMatrixLocation, 1, GL_FALSE, glm::value_ptr(mvpMatrix));
    glUniformMatrix4fv(mMatrixLocation, 1, GL_FALSE, glm::value_ptr(mMatrix));
    glUniformMatrix4fv(vMatrixLocation, 1, GL_FALSE, glm::value_ptr(vMatrix));
    glUniformMatrix4fv(mInvTrMatrixLocation, 1, GL_FALSE, glm::value_ptr(mInvTrMatrix));
    glUniform3f(lightPositionLocation, lightPosition.x, lightPosition.y, lightPosition.z);
    glUniform3f(lightColorPosition, lightColor.r, lightColor.g, lightColor.b);

    // draw the object
    //associate VBO with the corresponding vertex in the vertex shader
    //vertices
    glBindBuffer(GL_ARRAY_BUFFER, vbo[0]);
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, 0);
    glEnableVertexAttribArray(0);

    //normals
    glBindBuffer(GL_ARRAY_BUFFER, vbo[2]);
    glVertexAttribPointer(2, 3, GL_FLOAT, GL_FALSE, 0, 0);
    glEnableVertexAttribArray(2);

    //drawing object
    glDrawArrays(GL_TRIANGLES, 0, trianglesNumber);
}

