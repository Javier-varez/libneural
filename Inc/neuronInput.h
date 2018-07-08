
class Neuron;

class NeuronInput {
private:
    Neuron *neuron;
    double weight;

public:
    NeuronInput(Neuron &neuron, double initialWeight);
    double calculateContribution();
};
