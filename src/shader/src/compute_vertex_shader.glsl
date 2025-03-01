#version 330 core

in vec2 aScreenCoords;

out float pFactor;

void main()
{
    pFactor = (aScreenCoords.x + 1.0) / 2.0;
    gl_Position = vec4(aScreenCoords, 0.5, 1.0);
}