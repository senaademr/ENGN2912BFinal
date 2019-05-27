#version 400 core

layout(location = 0) in vec3 position;
layout(location = 1) in vec3 normal;
layout(location = 2) in vec4 weight;

uniform mat4 modelMatrix;
uniform mat4 viewMatrix;
uniform mat4 projMatrix;
uniform vec4 color;
uniform float pi;
uniform float time;
uniform vec3 center;

out vec4 fragC;
out vec4 worldNormal;

void main(void)
{
    float distx=position.x - center.x;
    float distz= position.z - center.z;
    float disty= (center.y - position.y)/center.y;
    float currTime = time+position.y;
    float offset = smoothstep(0.0, 1.0, max(0.f, -position.y-0.8f)/5.f);
    vec3 animate = (vec3(position.x, position.y, position.z)/100.f*sin(currTime)) * (1.f-offset);
    vec3 pos = position+animate;
    float xTime = time+position.y*0.3f;
    pos.x += distx*0.2f*(cos(xTime));
    pos.z += distz*0.2f*(cos(xTime));
    pos.y += 0.5f*xTime;

    worldNormal = projMatrix * viewMatrix * modelMatrix * vec4(normal, 0.0);
    gl_Position = projMatrix * viewMatrix * modelMatrix * vec4(pos, 1.0);
    fragC = color;
}
