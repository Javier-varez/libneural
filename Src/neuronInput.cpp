#import "neuron.h"
#import "neuronInput.h"

NeuronInput::NeuronInput(Neuron &neuron, double initialWeight) {
    this->neuron = &neuron;
    this->weight = initialWeight;
}
double NeuronInput::calculateContribution() {
    return 0.0;
}
