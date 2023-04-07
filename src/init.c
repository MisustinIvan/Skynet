#include <stdlib.h>
#include "network.h"
#include "randrange.h"

void initializeNetwork(struct Network*nw) {
    // initialize the input layer
    for (int i = 0; i < NUM_INPUTS; i++) {
        nw->inputs_layer[i].bias = (float)randrange(-1000000, 1000000)/1000000;
        nw->inputs_layer[i].output = 0.0;
        nw->inputs_layer[i].weights = NULL;
    }

    // initialize the hidden_layer
    for (int i = 0; i < NUM_HIDDEN; i++) {
        nw->hidden_layer[i].bias = (float)randrange(-1000000, 1000000)/1000000;
        nw->hidden_layer[i].output = 0.0;
        nw->hidden_layer[i].weights = (double*) malloc(NUM_INPUTS*sizeof(double));

        for (int j = 0; j < NUM_INPUTS; j++) {
            nw->hidden_layer[i].weights[j] = (float)randrange(-1000000, 1000000)/1000000;
        }
    }

    // initialize the output layer
    for (int i = 0; i < NUM_OUTPUT; i++) {
        nw->output_layer[i].bias = (float)randrange(-1000000, 1000000)/1000000;
        nw->output_layer[i].output = 0.0;
        nw->output_layer[i].weights = (double*) malloc(NUM_HIDDEN*sizeof(double));

        for (int j = 0; j < NUM_HIDDEN; j++) {
            nw->output_layer[i].weights[j] = (float)randrange(-1000000, 1000000)/1000000;
        }
    }
}
