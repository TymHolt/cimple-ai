#! /bin/bash

g++ src/main.cpp src/glad/glad.c src/core/compute/compute.cpp src/core/compute/opengl/compute_opengl.cpp src/core/compute/software/compute_software.cpp -I src -lglfw -o cimpleai