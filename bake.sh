#! /bin/bash

g++ src/shader/shader_baker.cpp src/util/file_loader.cpp -I src -o bake
./bake src/shader/src/compute_vertex_shader.glsl src/shader/baked/compute_vertex_shader.h compute_vertex_shader
./bake src/shader/src/compute_fragment_shader.glsl src/shader/baked/compute_fragment_shader.h compute_fragment_shader