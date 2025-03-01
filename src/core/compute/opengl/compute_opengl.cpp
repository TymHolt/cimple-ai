#include <core/compute/opengl/compute_opengl.h>
#include <core/compute/compute.h>
#include <glad/glad.h>



CAIDataTexture::CAIDataTexture(GLsizei width, GLsizei height)
{
    GLuint framebufferHandle = 0;
    glGenFramebuffers(1, &framebufferHandle);
    glBindFramebuffer(GL_FRAMEBUFFER, framebufferHandle);

    GLuint renderedTexture;
    glGenTextures(1, &renderedTexture);

    glBindTexture(GL_TEXTURE_2D, renderedTexture);

    // TODO: 3 data channels (r, g, b) -> Maybe increase to 4? Or make it variable?
    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, width, height, 0, GL_RGB, GL_UNSIGNED_BYTE, 0);

    // GL_NEAREST is important to access the data in the shader correctly
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);

    glFramebufferTexture(GL_FRAMEBUFFER, GL_COLOR_ATTACHMENT0, renderedTexture, 0);

    GLenum DrawBuffers[1] = {GL_COLOR_ATTACHMENT0};
    glDrawBuffers(1, DrawBuffers);

    if(glCheckFramebufferStatus(GL_FRAMEBUFFER) != GL_FRAMEBUFFER_COMPLETE)
        throw "Framebuffer creation failed";
}

CAIOpenGLComputePipeline::CAIOpenGLComputePipeline(size_t inputsCount, size_t resultsCount)
{
    // Init inputs, arguments and results texture

    inputsTexture = CAIDataTexture((GLuint) inputsCount, (GLuint) 1);    
    argumentsTexture = CAIDataTexture((GLuint) inputsCount, (GLuint) resultsCount);    
    resultsTexture = CAIDataTexture((GLuint) resultsCount, (GLuint) 1);    
    
    // Init shader program and vao

    programHandle = glCreateProgram();
    
    inputsTextureUL = glGetUniformLocation(programHandle, "uInputsTexture");
    argumentsTextureUL = glGetUniformLocation(programHandle, "uArgumentsTexture");
    inputsCountUL = glGetUniformLocation(programHandle, "uInputsCount");
    outputsCountUL = glGetUniformLocation(programHandle, "uOutputsCount");

    float vertexData[] = 
    {
        -1.0f, 1.0f,
        -1.0f, -1.0f,
        1.0f, -1.0f,
        1.0f, 1.0f
    };
    glGenVertexArrays(1, &vaoHandle);

    // Check for OpenGL errors (and throw exception)
}

void CAIOpenGLComputePipeline::setInputs(float *inputs) 
{
    // Upload data to inputs texture
    // Check for OpenGL errors (and throw exception)
}

void CAIOpenGLComputePipeline::setArguments(float *arguments) 
{
    // Upload data to arguments texture
    // Check for OpenGL errors (and throw exception)
}

void CAIOpenGLComputePipeline::compute(float *results) 
{
    // Use results texture as frame buffer
    // Uniform and use textures
    // "Draw" call
    // Fetch results from texture
    // Check for OpenGL errors (and throw exception)
}