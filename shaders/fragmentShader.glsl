#version 430

out vec4 color;

in vec3 normal;
in vec3 fragmentPosition;

uniform mat4 mvpMatrix;
uniform mat4 vMatrix;
uniform mat4 mMatrix;
uniform mat4 mInvTrMatrix;
uniform vec3 lightPosition; //in world space;;
uniform vec3 lightColor;

void main() {
    //ambient color strength
    float ambientStrength = 0.1;
    //ambient light
    vec3 ambient = ambientStrength * lightColor;

    vec3 N = normalize(normal);
    //calculate light-object vector
    vec3 lightDir = normalize(lightPosition - fragmentPosition);

    //calcuate diffuse light contribution
    float diff = max(dot(N, lightDir), 0.0);
    vec3 diffuse = diff * lightColor;

    vec3 objectColor = vec3(1, 0, 0);
    vec3 result = (ambient + diffuse) * objectColor;

    color = vec4(result, 1);
}
