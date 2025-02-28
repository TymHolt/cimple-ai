#ifndef compute_vertex_shader_DEF
#define compute_vertex_shader_DEF

#include <string>

namespace compute_vertex_shader 
{
	const std::string content =
		"#version 330 core\n"
		"\n"
		"// in type in_variable_name;\n"
		"\n"
		"// out type out_variable_name;\n"
		"  \n"
		"// uniform type uniform_name;\n"
		"  \n"
		"void main()\n"
		"{\n"
		"  gl_Position = vec4(0.0, 0.0, 0.0, 1.0);\n"
		"}\n"
		"";
}

#endif
