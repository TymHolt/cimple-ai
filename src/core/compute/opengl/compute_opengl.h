#ifndef COMPUTE_OPENGL_H
#define COMPUTE_OPENGL_H

#include <core/compute/compute.h>
#include <stdlib.h>
#include <glad/glad.h>

class CAIDataTexture
{
    private:
        GLuint framebufferHandle;
        GLuint textureHandle;
    public:
        CAIDataTexture(GLsizei width = 1, GLsizei height = 1);    
};

class CAIOpenGLComputePipeline : public CAIComputePipeline
{
    private:
        CAIDataTexture inputsTexture, argumentsTexture, resultsTexture;
    public:
        CAIOpenGLComputePipeline(size_t inputsCount = 1, size_t resultsCount = 1);
        void setInputs(float *inputs) override;
        void setArguments(float *arguments) override;
        void compute(float *results) override;
};

#endif