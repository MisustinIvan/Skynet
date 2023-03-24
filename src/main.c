#include <stdio.h>
#include <stdlib.h>

#define NUM_INPUTS 4
#define NUM_HIDDEN 4
#define NUM_OUTPUT 2

struct Neuron{
    double * weights;
    double output;
    double bias;
};

struct Network{
    struct Neuron inputs_layer[NUM_INPUTS];
    struct Neuron hidden_layer[NUM_HIDDEN];
    struct Neuron output_layer[NUM_OUTPUT];
};

double max(double x, double y) {
    if (x > y) { return x; }
    else if (x<y) { return y; }
    else { return x; }
}

void initializeNetwork(struct Network*nw) {
    // initialize the input layer
    for (int i = 0; i < NUM_INPUTS; i++) {
        nw->inputs_layer[i].bias = 0.0;
        nw->inputs_layer[i].output = 0.0;
        nw->inputs_layer[i].weights = NULL;
    }

    // initialize the hidden_layer
    for (int i = 0; i < NUM_HIDDEN; i++) {
        nw->hidden_layer[i].bias = 0.0;
        nw->hidden_layer[i].output = 0.0;
        nw->hidden_layer[i].weights = (double*) malloc(NUM_INPUTS*sizeof(double));

        for (int j = 0; j < NUM_INPUTS; j++) {
            nw->hidden_layer[i].weights[j] = 1.0;
        }
    }

    // initialize the output layer
    for (int i = 0; i < NUM_OUTPUT; i++) {
        nw->output_layer[i].bias = 0.0;
        nw->output_layer[i].output = 0.0;
        nw->output_layer[i].weights = (double*) malloc(NUM_HIDDEN*sizeof(double));

        for (int j = 0; j < NUM_HIDDEN; j++) {
            nw->output_layer[i].weights[j] = 1.0;
        }
    }
}

void computeNetwork(struct Network * nw, float * in, float * out) {
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
        nw->hidden_layer[i].output = max(0, weighted_sum + nw->hidden_layer[i].bias);
    }

    // output layer
    for (int i = 0; i < NUM_OUTPUT; i++) {
        float weighted_sum = 0.0;
        
        for (int j = 0; j < NUM_HIDDEN; j++) {
            weighted_sum += nw->output_layer[i].weights[j] * nw->hidden_layer[j].output;
        }

        nw->output_layer[i].output = max(0, weighted_sum + nw->output_layer[i].bias);
        out[i] = nw->output_layer[i].output;
    }
}

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

int main(int argc, char *argv[]) {
    struct Network nw;
    initializeNetwork(&nw);

//    float * inputs = malloc(NUM_INPUTS*sizeof(double));
    float inputs[4] = {1,1,1,1};

    float * outputs = malloc(NUM_OUTPUT*sizeof(double));

    computeNetwork(&nw, inputs, outputs);

    for (int i = 0; i < NUM_OUTPUT; i++) {
        printf("%f\n", outputs[i]);
    }
//    logNetworkStdin(&nw);
//    logNetworkFile(&nw);


    return 0;
}
