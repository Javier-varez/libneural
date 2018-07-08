#include <vector>
#include "neuronInput.h"

class Neuron {
private:
    double offset;
    std::vector<NeuronInput> inputs;
    virtual double activation(double inputValue);

public:
    Neuron(double offset);
    void bindInput(Neuron &neuron, double initialWeight);
    double computeOutput();
};
