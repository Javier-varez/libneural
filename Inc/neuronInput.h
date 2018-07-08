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

#ifndef INPUT_NEURON_H
#define INPUT_NEURON_H

class Neuron;

class NeuronInput {
private:
    Neuron *neuron;
    double weight;

public:
    NeuronInput(Neuron &neuron, double initialWeight);
    double calculateContribution();
};

#endif
