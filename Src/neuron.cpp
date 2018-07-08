#include <vector>
#include "neuron.h"

Neuron::Neuron(double offset) {
    this->offset = offset;
}

void Neuron::bindInput(Neuron &neuron, double initialWeight) {
    inputs.push_back(NeuronInput(neuron, initialWeight));
}

double Neuron::computeOutput() {
    double output = offset;
    for (int i = 0; i < inputs.size(); i++) {
        output += inputs[i].calculateContribution();
    }
    return output;
}

// zero activation function being used
double Neuron::activation(double inputValue) {
    return 0;
}
