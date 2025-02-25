#include <core/compute/compute.h>
#include <stdlib.h>

class CAIComputePipeline {
    private:
        size_t inputSize, outputSize;
        int inputTextureHandle, argumentsTextureHandle, outputTextureHandle;

        int generateDataTexture(size_t width, size_t height) {
            throw "Generating data textures not implemented yet";
        }

    public:
        CAIComputePipeline(size_t inputSize, size_t outputSize) {
            if(inputSize == 0 || outputSize == 0)
                throw "Sizes must be greater than 0";
                
            this->inputSize = inputSize;
            this->outputSize = outputSize;
            this->inputTextureHandle = generateDataTexture(inputSize, 1);
            this->argumentsTextureHandle = generateDataTexture(inputSize, outputSize);
            this->outputTextureHandle = generateDataTexture(outputSize, 1);
        }

};