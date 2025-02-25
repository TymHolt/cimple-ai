#! /bin/bash

g++ src/main.cpp src/glad/glad.c src/core/compute.cpp -I src -lglfw -o cimpleai