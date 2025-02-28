# CimpleAI

**WARNING** This repository is in early development

### Dependencies/Requirements:
* OpenGL 3.3 (or higher)
* [GLFW 3](https://www.glfw.org/)

Install GLFW 3 on Ubuntu:
```
sudo apt-get install libglfw3 libglfw3-dev
```

### Build
#### 1. (Optional) Bake shaders

Shaders used by the graphics pipeline need to be baked into the source code. This should have
already happened, but if you have modified the shaders or just want a clean build, execute the
following:

```
bash bake.sh
```

#### 2. Build:
```
bash build.sh
```