#version 330 core
#precision mediump float

in float pFactor;

// Render to to target 0 (Color attachement)
layout(location = 0) out vec3 oColor;

uniform sampler2D uInputsTexture;
uniform sampler2D uArgumentsTexture;
uniform int uInputsCount;
uniform int uOutputsCount;

float normalizeCoord(float coord, float max) 
{
    return (coord / max) * 2.0 - 1.0;
}

void main()
{
    int inputIndex = int(floor(pFactor * float(uInputsCount)));
    float argumentV = nornalizeCoord(float(inputIndex), float(uInputsCount));
    float input = texture(uInputsTexture, vec2(argumentV, 0.0));

    float total = 0.0f;
    for(int outputIndex = 0; outputIndex < outputsCount; outputIndex++)
    {
        float argumentU = normalizeCoord(float(outputIndex), float(uOutputsCount));
        float argument = texture(uArgumentsTexture, vec2(argumentU, argumentV));
        total += input * argument;
    }

    out_variable_name = vec4(total, 0.0, 0.0, 1.0);
}