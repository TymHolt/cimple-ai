#ifndef compute_fragment_shader_DEF
#define compute_fragment_shader_DEF

#include <string>

namespace compute_fragment_shader 
{
	const std::string content =
		"#version 330 core\n"
		"#precision mediump float\n"
		"\n"
		"in float pFactor;\n"
		"\n"
		"// Render to to target 0 (Color attachement)\n"
		"layout(location = 0) out vec3 oColor;\n"
		"\n"
		"uniform sampler2D uInputsTexture;\n"
		"uniform sampler2D uArgumentsTexture;\n"
		"uniform int uInputsCount;\n"
		"uniform int uOutputsCount;\n"
		"\n"
		"float normalizeCoord(float coord, float max) \n"
		"{\n"
		"    return (coord / max) * 2.0 - 1.0;\n"
		"}\n"
		"\n"
		"void main()\n"
		"{\n"
		"    int inputIndex = int(floor(pFactor * float(uInputsCount)));\n"
		"    float argumentV = nornalizeCoord(float(inputIndex), float(uInputsCount));\n"
		"    float input = texture(uInputsTexture, vec2(argumentV, 0.0));\n"
		"\n"
		"    float total = 0.0f;\n"
		"    for(int outputIndex = 0; outputIndex < outputsCount; outputIndex++)\n"
		"    {\n"
		"        float argumentU = normalizeCoord(float(outputIndex), float(uOutputsCount));\n"
		"        float argument = texture(uArgumentsTexture, vec2(argumentU, argumentV));\n"
		"        total += input * argument;\n"
		"    }\n"
		"\n"
		"    out_variable_name = vec4(total, 0.0, 0.0, 1.0);\n"
		"}\n"
		"";
}

#endif
