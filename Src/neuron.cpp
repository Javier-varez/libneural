/*
 * libneuron
 * Copyright (C) 2018 AllThingsEmbedded
 * 
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 * 
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 * 
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

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
    return this->activation(output);
}

// zero activation function being used
double Neuron::activation(double inputValue) {
    return 0;
}
