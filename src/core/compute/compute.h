#ifndef COMPUTE_H
#define COMPUTE_H

class CAIComputePipeline
{
    public:
        virtual void setInputs(float *inputs);
        virtual void setArguments(float *arguments);
        virtual void compute(float *results);
};

#endif