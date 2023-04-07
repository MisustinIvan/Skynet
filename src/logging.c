#include <stdio.h>
#include <stdlib.h>

#include "main.h"
#include "network.h"

void logNetworkFile(struct Network*nw) {
    FILE *file = fopen("./bin/network_info", "w");
    fprintf(file, "Network Info:\n");
    fprintf(file, "\n");
    fprintf(file, "Input Layer:\n");
    for (int i = 0; i < NUM_INPUTS; i++) {
        fprintf(file, "  Neuron index: %d\n", i);
        fprintf(file, "    bias: %f\n", nw->inputs_layer[i].bias);
        fprintf(file, "    output: %f\n", nw->inputs_layer[i].output);
    }
    fprintf(file, "\n");
    fprintf(file, "Hidden Layer:\n");
    for (int i = 0; i < NUM_HIDDEN; i++) {
        fprintf(file, "  Neuron index: %d\n", i);
        fprintf(file, "    bias: %f\n", nw->hidden_layer[i].bias);
        fprintf(file, "    output: %f\n", nw->hidden_layer[i].output);
        fprintf(file, "    input weights: \n");
        for (int j = 0; j < NUM_INPUTS; j++) { fprintf(file, "      input[%d]:%f\n", j, nw->hidden_layer[i].weights[j]); }
    }
    fprintf(file, "\n");
    fprintf(file, "Output Layer:\n");
    for (int i = 0; i < NUM_OUTPUT; i++) {
        fprintf(file, "  Neuron index: %d\n", i);
        fprintf(file, "    bias: %f\n", nw->output_layer[i].bias);
        fprintf(file, "    output: %f\n", nw->output_layer[i].output);
        fprintf(file, "    input weights: \n");
        for (int j = 0; j < NUM_HIDDEN; j++) { fprintf(file, "      input[%d]:%f\n", j, nw->output_layer[i].weights[j]); }
    }
    fclose(file);
}

void logNetworkStdin(struct Network*nw) {
    printf("Network Info:\n");
    printf("\n");
    printf("Input Layer:\n");
    for (int i = 0; i < NUM_INPUTS; i++) {
        printf("  Neuron index: %d\n", i);
        printf("    bias: %f\n", nw->inputs_layer[i].bias);
        printf("    output: %f\n", nw->inputs_layer[i].output);
    }
    printf("\n");
    printf("Hidden Layer:\n");
    for (int i = 0; i < NUM_HIDDEN; i++) {
        printf("  Neuron index: %d\n", i);
        printf("    bias: %f\n", nw->hidden_layer[i].bias);
        printf("    output: %f\n", nw->hidden_layer[i].output);
        printf("    input weights: \n");
        for (int j = 0; j < NUM_INPUTS; j++) { printf("      input[%d]:%f\n", j, nw->hidden_layer[i].weights[j]); }
    }
    printf("\n");
    printf("Output Layer:\n");
    for (int i = 0; i < NUM_OUTPUT; i++) {
        printf("  Neuron index: %d\n", i);
        printf("    bias: %f\n", nw->output_layer[i].bias);
        printf("    output: %f\n", nw->output_layer[i].output);
        printf("    input weights: \n");
        for (int j = 0; j < NUM_HIDDEN; j++) { printf("      input[%d]:%f\n", j, nw->output_layer[i].weights[j]); }
    }
}
