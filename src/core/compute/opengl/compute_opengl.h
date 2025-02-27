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
        CAIDataTexture(GLsizei width, GLsizei height);    
};

class CAIOpenGLComputePipeline : public CAIComputePipeline
{
    private:
        
    public:
        CAIOpenGLComputePipeline(size_t inputsCount, size_t argumentsCount, size_t resultsCount);
        void setInputs(float *inputs) override;
        void setArguments(float *arguments) override;
        void compute(float *results) override;
};

#endif