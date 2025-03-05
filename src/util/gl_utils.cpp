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
    m_programHandle = glCreateProgram();
    GLuint vertexShaderHandle = createShader(GL_VERTEX_SHADER, vertexShaderSource);
    GLuint fragmentShaderHandle = createShader(GL_FRAGMENT_SHADER, fragmentShaderSource);
    glAttachShader(m_programHandle, vertexShaderHandle);
    glAttachShader(m_programHandle, fragmentShaderHandle);
    glLinkProgram(m_programHandle);

    glDeleteShader(vertexShaderHandle); // Shaders are not needed anymore after linking
    glDeleteShader(fragmentShaderHandle); 

    int linkState;
    char log[MAX_LOG_LENGTH];
    glGetProgramiv(m_programHandle, GL_LINK_STATUS, &linkState);

    if(!linkState)
    {
        glGetProgramInfoLog(m_programHandle, MAX_LOG_LENGTH, NULL, log);
        std::cerr << "Progran link log: " << log << std::endl;
        throw "Program linking failed";
    }
}

CAIGLShaderProgram::~CAIGLShaderProgram()
{
    glDeleteProgram(m_programHandle);
}

GLuint CAIGLShaderProgram::getProgramHandle()
{
    return m_programHandle;
}

void CAIGLShaderProgram::use()
{
    glUseProgram(m_programHandle);
}

GLuint CAIGLShaderProgram::getUniformLocation(std::string uniformName)
{
    const char *uniformNameCString = uniformName.c_str();
    return glGetUniformLocation(m_programHandle, uniformNameCString);
}  

CAIGLVertexArrayObject::CAIGLVertexArrayObject(CAIVertexData *vertexData, size_t dataCount,
    short *indices, size_t indexCount)
{
    glGenVertexArrays(1, &m_vaoHandle);
    
    // +1 for the element buffer
    m_vboHandleCount = dataCount + 1;
    m_vboHandles = (GLuint *) malloc(sizeof(GLuint) * m_vboHandleCount);
    glGenBuffers(m_vboHandleCount, m_vboHandles);
    
    for(GLsizei vboHandleIndex = 0; vboHandleIndex < m_vboHandleCount - 1; vboHandleIndex++)
    {
        GLuint vboHandle = m_vboHandles[vboHandleIndex];
        CAIVertexData vertexDataElement = vertexData[vboHandleIndex];

        glBindBuffer(GL_ARRAY_BUFFER, vboHandle);  
        glBufferData(GL_ARRAY_BUFFER, vertexDataElement.dataSize, vertexDataElement.data, GL_STATIC_DRAW);
        //glAttribArray
        //glEnable
    }

    // TODO Element buffer
}

CAIGLVertexArrayObject::~CAIGLVertexArrayObject()
{
    glDeleteVertexArrays(1, &m_vaoHandle);
    glDeleteBuffers(m_vboHandleCount, m_vboHandles);
    free(m_vboHandles);
}

GLuint CAIGLVertexArrayObject::getVaoHandle()
{
    return m_vaoHandle;
}

GLuint *CAIGLVertexArrayObject::getVboHandles()
{
    return m_vboHandles;
}

GLsizei CAIGLVertexArrayObject::getVboHandleCount()
{
    return m_vboHandleCount;
}

short CAIGLVertexArrayObject::getVertexCount()
{
    return m_vertexCount;
}

void CAIGLVertexArrayObject::use()
{
    glBindVertexArray(m_vaoHandle);
}

void caiglIssueDrawCall(short vertexCount)
{

}