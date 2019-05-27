#version 400 core
in vec4 fragC;
in vec4 worldNormal;

out vec4 fragColor;

void main(void)
{
    fragColor = dot(worldNormal, worldNormal)*fragC;
}
