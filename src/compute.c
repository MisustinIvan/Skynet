#include "main.h"
#include "max.h"
#include "network.h"
#include "sigmoid.h"
void computeNetwork(struct Network * nw, double * in, double * out) {

    // give the input neurons their input values
    for (int i = 0; i < NUM_INPUTS; i++) {
        nw->inputs_layer[i].output = in[i];
    }

    // hidden layer bullshit
    for (int i = 0; i < NUM_HIDDEN; i++) {
        float weighted_sum = 0.0;
        
        // multiply all the weights with the input values -> add them to the sum
        for (int j = 0; j < NUM_INPUTS; j++) {
            weighted_sum += nw->hidden_layer[i].weights[j] * nw->inputs_layer[j].output;
        }
        // stick the sum into the activation function
        nw->hidden_layer[i].output = sigmoid(weighted_sum + nw->hidden_layer[i].bias);
    }

    // output layer
    for (int i = 0; i < NUM_OUTPUT; i++) {
        float weighted_sum = 0.0;
        
        for (int j = 0; j < NUM_HIDDEN; j++) {
            weighted_sum += nw->output_layer[i].weights[j] * nw->hidden_layer[j].output;
        }

        nw->output_layer[i].output = sigmoid(weighted_sum + nw->output_layer[i].bias);
        out[i] = nw->output_layer[i].output;
    }
}
