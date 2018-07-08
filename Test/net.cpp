#include "neuronLayer.h"
#include "linearNeuron.h"
#include "dummyNeuron.h"

#include <iostream>

int main(int argc, char *argv[]) {
    NeuronLayer<DummyNeuron> inputLayer;
    NeuronLayer<LinearNeuron> hiddenLayer;
    NeuronLayer<LinearNeuron> outputLayer;

    outputLayer.addNeuron(2.0);
    hiddenLayer.addNeuron(1.0);
    inputLayer.addNeuron(123.9);

    outputLayer.connectLayer(hiddenLayer);
    hiddenLayer.connectLayer(inputLayer);

    LinearNeuron outputNeuron = outputLayer.getNeurons()[0];

    std::cout << "ComputeOutput: " << outputNeuron.computeOutput() << std::endl;
}
