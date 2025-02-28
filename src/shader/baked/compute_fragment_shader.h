#ifndef compute_fragment_shader_DEF
#define compute_fragment_shader_DEF

#include <string>

namespace compute_fragment_shader 
{
	const std::string content =
		"#version 330 core\n"
		"#precision mediump float\n"
		"\n"
		"// in type in_variable_name;\n"
		"\n"
		"// out type out_variable_name;\n"
		"  \n"
		"// uniform type uniform_name;\n"
		"  \n"
		"void main()\n"
		"{\n"
		"  out_variable_name = vec4(1.0, 1.0, 1.0, 1.0);\n"
		"}\n"
		"";
}

#endif
