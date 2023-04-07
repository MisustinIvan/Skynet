#include "main.h"
#include "neuron.h"

#ifndef NETWORK_H
#define NETWORK_H
struct Network{
    struct Neuron inputs_layer[NUM_INPUTS];
    struct Neuron hidden_layer[NUM_HIDDEN];
    struct Neuron output_layer[NUM_OUTPUT];
};
#endif
