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

#include "neuronLayer.h"
#include "linearNeuron.h"
#include "dummyNeuron.h"

#include <iostream>

#define ASSERT(x) if (x) { std::cout << "Error: line " << __LINE__ << "\tASSERT(" << #x << ")" << std::endl; exit(1); }

int main(int argc, char *argv[]) {
    NeuronLayer<DummyNeuron> inputLayer;
    NeuronLayer<LinearNeuron> hiddenLayer;
    NeuronLayer<LinearNeuron> outputLayer;

    outputLayer.addNeuron(-3.0);
    hiddenLayer.addNeuron(1.0);
    hiddenLayer.addNeuron(5.2);
    inputLayer.addNeuron(123.9);
    inputLayer.addNeuron(-45.3);
    inputLayer.addNeuron(18.5);

    outputLayer.connectLayer(hiddenLayer);
    hiddenLayer.connectLayer(inputLayer);

    LinearNeuron outputNeuron = outputLayer.getNeurons()[0];

    ASSERT(outputNeuron.computeOutput() != 197.4);

    std::cout << "Tests completed successfully" << std::endl;
}
