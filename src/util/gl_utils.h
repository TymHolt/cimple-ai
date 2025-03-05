#ifndef GL_UTILS_H
#define GL_UTILS_H

#include <string>
#include <glad/glad.h>

class CAIGLShaderProgram
{
    private:
        GLuint m_programHandle;
    public:
        CAIGLShaderProgram(std::string vertexShaderSource = "", std::string fragmentShaderSource = "");
        ~CAIGLShaderProgram();
        GLuint getProgramHandle();
        void use();      
        GLuint getUniformLocation(std::string uniformName);
};

typedef struct CAIVertexDataStruct
{
    float *data;
    size_t dataSize, vertexSize;
} CAIVertexData;

class CAIGLVertexArrayObject
{
    private:
        GLuint m_vaoHandle;
        GLuint *m_vboHandles;
        GLsizei m_vboHandleCount;
        short m_vertexCount;
    public:
        CAIGLVertexArrayObject(CAIVertexData *vertexData, size_t dataCount, short *indicex, size_t indexCount);
        ~CAIGLVertexArrayObject();
        GLuint getVaoHandle();
        GLuint *getVboHandles();
        GLsizei getVboHandleCount();
        short getVertexCount();
        void use();
};

void caiglIssueDrawCall(short vertexCount);

#endif