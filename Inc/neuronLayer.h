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

#ifndef NEURON_LAYER_H
#define NEURON_LAYER_H

#include <vector>
#include "neuron.h"

template <class T>
class NeuronLayer {
private:
    std::vector<T> neurons;

public:
    void addNeuron(double initialOffset);
    template <class S> void connectLayer(NeuronLayer<S> &previousLayer);
    std::vector<T>& getNeurons();
    unsigned int getNeuronCount();
};

template <class T>
void NeuronLayer<T>::addNeuron(double initialOffset) {
    neurons.push_back(T(initialOffset));
}

template <class T>
template <class S>
void NeuronLayer<T>::connectLayer(NeuronLayer<S> &previousLayer) {
    for (int i = 0; i < neurons.size(); i++) {
        for (int j = 0; j < previousLayer.getNeuronCount(); j++) {
            neurons[i].bindInput(previousLayer.getNeurons()[j], 1.0);
        }
    }
}

template <class T>
std::vector<T>& NeuronLayer<T>::getNeurons() {
    return neurons;
}

template <class T>
unsigned int NeuronLayer<T>::getNeuronCount() {
    return neurons.size();
}

#endif
