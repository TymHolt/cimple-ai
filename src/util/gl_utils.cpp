#include <util/gl_utils.h>
#include <iostream>

#define MAX_LOG_LENGTH 1024

GLuint createShader(GLuint type, std::string source)
{
    GLuint shaderHandle = glCreateShader(type);
    const char *shaderSource = source.c_str();
    glShaderSource(shaderHandle, 1, &shaderSource, NULL);
    glCompileShader(shaderHandle);

    int compileState;
    char log[MAX_LOG_LENGTH];
    glGetShaderiv(shaderHandle, GL_COMPILE_STATUS, &compileState);

    if(!compileState)
    {
        glGetShaderInfoLog(shaderHandle, MAX_LOG_LENGTH, NULL, log);
        std::cerr << "Shader compile log: " << log << std::endl;
        throw "Shader compilation failed";
    }

    return shaderHandle;
}

CAIGLShaderProgram::CAIGLShaderProgram(std::string vertexShaderSource, std::string fragmentShaderSource)
{
    programHandle = glCreateProgram();
    GLuint vertexShaderHandle = createShader(GL_VERTEX_SHADER, vertexShaderSource);
    GLuint fragmentShaderHandle = createShader(GL_FRAGMENT_SHADER, fragmentShaderSource);
    glAttachShader(programHandle, vertexShaderHandle);
    glAttachShader(programHandle, fragmentShaderHandle);
    glLinkProgram(programHandle);

    glDeleteShader(vertexShaderHandle); // Shaders are not needed anymore after linking
    glDeleteShader(fragmentShaderHandle); 

    int linkState;
    char log[MAX_LOG_LENGTH];
    glGetProgramiv(programHandle, GL_LINK_STATUS, &linkState);

    if(!linkState)
    {
        glGetProgramInfoLog(programHandle, MAX_LOG_LENGTH, NULL, log);
        std::cerr << "Progran link log: " << log << std::endl;
        throw "Program linking failed";
    }
}

CAIGLShaderProgram::~CAIGLShaderProgram()
{
    glDeleteProgram(programHandle);
}

GLuint CAIGLShaderProgram::getProgramHandle()
{
    return programHandle;
}

void CAIGLShaderProgram::use()
{
    glUseProgram(programHandle);
}

GLuint CAIGLShaderProgram::getUniformLocation(std::string uniformName)
{
    const char *uniformNameCString = uniformName.c_str();
    return glGetUniformLocation(programHandle, uniformNameCString);
}  