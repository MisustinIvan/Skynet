#include "network.h"
#include "sigmoid.h"

#define LEARNING_RATE 2

// takes in the network, the input values and the expected outputs
void trainNetwork(struct Network *nw, double inputs[NUM_INPUTS], double outputs[NUM_OUTPUT]) {
    float hidden_outputs[NUM_HIDDEN];
    float final_outputs[NUM_OUTPUT];

    // calculate the outputs of the hidden layer
    // loop through each neuron
    for (int i = 0; i < NUM_HIDDEN; i++) {
        // initialize the activation_value
        float activation_value = nw->hidden_layer[i].bias;
        for (int j = 0; j < NUM_INPUTS; j++) {
            // compute the weighted sum
            activation_value += inputs[j] * nw->hidden_layer[i].weights[j];
        }
        hidden_outputs[i] = sigmoid(activation_value);
    }

    // calculate the outputs of the output layer
    // loop through each neuron
    for (int i = 0; i < NUM_OUTPUT; i++) {
        // initialize the activation_value
        float activation_value = nw->output_layer[i].bias;
        for (int j = 0; j < NUM_HIDDEN; j++) {
            // compute the weighted sum
            activation_value += hidden_outputs[j] * nw->output_layer[i].weights[j];
        }
        final_outputs[i] = sigmoid(activation_value);
    }

    // compute the cost
    
    float error = 0.0;
    for (int i = 0; i < NUM_OUTPUT; i++) {
        float diff = outputs[i] - final_outputs[i];
        // square the difference so that big errors contribute more to the total error
        error += diff * diff;
    }

    // backpropagation black magic

    float output_diffs[NUM_OUTPUT];
    float hidden_diffs[NUM_HIDDEN];

    // update the weights and biases of the output layer based on the LEARNING_RATE and the mistakes
    for (int i = 0; i < NUM_OUTPUT; i++) {
        float diff = (outputs[i] - final_outputs[i]) * sigmoid_derivative(final_outputs[i]);
        output_diffs[i] = diff;
        for (int j = 0; j < NUM_HIDDEN; j++) {
            nw->output_layer[i].weights[j] += LEARNING_RATE * diff * hidden_outputs[j];
        }
        nw->output_layer[i].bias += LEARNING_RATE * diff;
    }

    // update the hidden_layer weights and biases
    for (int i = 0; i < NUM_HIDDEN; i++) {
        float diff = 0.0;
        for (int j = 0; j < NUM_OUTPUT; j++) {
            diff += output_diffs[j] * nw->output_layer[j].weights[i];
        }
        diff *= sigmoid_derivative(hidden_outputs[i]);
        hidden_diffs[i] = diff;

        for (int j = 0; j < NUM_INPUTS; j++) {
            nw->hidden_layer[i].weights[j] += LEARNING_RATE * diff * inputs[j];
        }
        nw->hidden_layer[i].bias += LEARNING_RATE * diff;
    }
}
