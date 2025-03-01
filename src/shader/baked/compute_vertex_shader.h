#ifndef compute_vertex_shader_DEF
#define compute_vertex_shader_DEF

#include <string>

namespace compute_vertex_shader 
{
	const std::string content =
		"#version 330 core\n"
		"\n"
		"in vec2 aScreenCoords;\n"
		"\n"
		"out float pFactor;\n"
		"\n"
		"void main()\n"
		"{\n"
		"    pFactor = (aScreenCoords.x + 1.0) / 2.0;\n"
		"    gl_Position = vec4(aScreenCoords, 0.5, 1.0);\n"
		"}\n"
		"";
}

#endif
