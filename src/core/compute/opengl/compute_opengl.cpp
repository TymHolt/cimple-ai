#include <core/compute/opengl/compute_opengl.h>
#include <core/compute/compute.h>
#include <glad/glad.h>
#include <iostream>
#include <shader/baked/compute_vertex_shader.h>
#include <shader/baked/compute_fragment_shader.h>

CAIDataTexture::CAIDataTexture(GLsizei width, GLsizei height)
{
    m_framebufferHandle = 0;
    glGenFramebuffers(1, &m_framebufferHandle);
    glBindFramebuffer(GL_FRAMEBUFFER, m_framebufferHandle);

    m_textureHandle;
    glGenTextures(1, &m_textureHandle);

    glBindTexture(GL_TEXTURE_2D, m_textureHandle);

    // TODO: 3 data channels (r, g, b) -> Maybe increase to 4? Or make it variable?
    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, width, height, 0, GL_RGB, GL_UNSIGNED_BYTE, 0);

    // GL_NEAREST is important to access the data in the shader correctly
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);

    glFramebufferTexture(GL_FRAMEBUFFER, GL_COLOR_ATTACHMENT0, m_textureHandle, 0);

    GLenum DrawBuffers[1] = {GL_COLOR_ATTACHMENT0};
    glDrawBuffers(1, DrawBuffers);

    if(glCheckFramebufferStatus(GL_FRAMEBUFFER) != GL_FRAMEBUFFER_COMPLETE)
        throw "Framebuffer creation failed";

    glBindFramebuffer(GL_FRAMEBUFFER, 0);
}

CAIOpenGLComputePipeline::CAIOpenGLComputePipeline(size_t inputsCount, size_t resultsCount)
{
    // Init inputs, arguments and results texture

    m_inputsTexture = CAIDataTexture((GLuint) inputsCount, (GLuint) 1);    
    m_argumentsTexture = CAIDataTexture((GLuint) inputsCount, (GLuint) resultsCount);    
    m_resultsTexture = CAIDataTexture((GLuint) resultsCount, (GLuint) 1);    
    
    // Init shader program and vao

    m_shaderProgram = CAIGLShaderProgram(compute_vertex_shader::content, compute_fragment_shader::content);

    m_inputsTextureUL = m_shaderProgram.getUniformLocation("uInputsTexture");
    m_argumentsTextureUL = m_shaderProgram.getUniformLocation("uArgumentsTexture");
    m_inputsCountUL = m_shaderProgram.getUniformLocation("uInputsCount");
    m_outputsCountUL = m_shaderProgram.getUniformLocation("uOutputsCount");

    float vertexData[] = 
    {
        -1.0f, 1.0f,
        -1.0f, -1.0f,
        1.0f, -1.0f,
        1.0f, 1.0f
    };

    // Check for OpenGL errors (and throw exception)

    GLenum errorCode = glGetError();
    if(errorCode != GL_NO_ERROR) 
    {
        std::cerr << "OpenGL error encountered: " << errorCode << std::endl;
        throw "OpenGL error while creating compute pipeline";
    }
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

    m_shaderProgram.use();

    // "Draw" call
    // Fetch results from texture
    // Check for OpenGL errors (and throw exception)
}