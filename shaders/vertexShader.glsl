#version 430

layout (location=0) in vec3 vertexPosition; //for model space
//layout (location=0) in vec3 vertexUV;
layout (location=2) in vec3 vertexNormal;   //for model space

out vec3 normal;            //normal vector in model space
out vec3 fragmentPosition;  //vertex position in model space

uniform mat4 mvpMatrix;
uniform mat4 vMatrix;
uniform mat4 mMatrix;
uniform mat4 mInvTrMatrix;
uniform vec3 lightPosition; //in world space;
uniform vec3 lightColor;

void main() {
    gl_Position = mvpMatrix * vec4(vertexPosition, 1);
    //adapt normal to model space/transform
    normal = mat3(mInvTrMatrix) * vertexNormal;
    fragmentPosition = (mMatrix * vec4(vertexPosition, 1)).xyz;
}
