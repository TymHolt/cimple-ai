#ifndef GL_UTILS_H
#define GL_UTILS_H

#include <string>
#include <glad/glad.h>

class CAIGLShaderProgram
{
    private:
        GLuint programHandle;
    public:
        CAIGLShaderProgram(std::string vertexShaderSource = "", std::string fragmentShaderSource = "");
        ~CAIGLShaderProgram();
        GLuint getProgramHandle();
        void use();      
        GLuint getUniformLocation(std::string uniformName);
};

#endif