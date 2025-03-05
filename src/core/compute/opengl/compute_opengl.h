#ifndef COMPUTE_OPENGL_H
#define COMPUTE_OPENGL_H

#include <core/compute/compute.h>
#include <stdlib.h>
#include <glad/glad.h>
#include <util/gl_utils.h>

class CAIDataTexture
{
    private:
        GLuint m_framebufferHandle;
        GLuint m_textureHandle;
    public:
        CAIDataTexture(GLsizei width = 1, GLsizei height = 1);    
};

class CAIOpenGLComputePipeline : public CAIComputePipeline
{
    private:
        CAIDataTexture m_inputsTexture, m_argumentsTexture, m_resultsTexture;
        GLuint m_vaoHandle;
        CAIGLShaderProgram m_shaderProgram;
        GLuint m_inputsTextureUL, m_argumentsTextureUL;
        GLuint m_inputsCountUL, m_outputsCountUL;
    public:
        CAIOpenGLComputePipeline(size_t inputsCount = 1, size_t resultsCount = 1);
        void setInputs(float *inputs) override;
        void setArguments(float *arguments) override;
        void compute(float *results) override;
};

#endif