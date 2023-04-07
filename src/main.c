#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "main.h"
#include "init.h"
#include "network.h"
#include "compute.h"
#include "logging.h"
#include "training.h"
#include "data.h"
#include "randrange.h"

int main(int argc, char *argv[]) {
    srand(time(0));

    struct Network nw;
    initializeNetwork(&nw);

//    float * inputs = malloc(NUM_INPUTS*sizeof(double));

    double * outputs = malloc(NUM_OUTPUT*sizeof(double));

    struct Data dt;

    loadTrainingData(&dt);

    //computeNetwork(&nw, inputs, outputs);
    //logNetworkStdin(&nw);
    //for (int i = 0; i < NUM_OUTPUT; i++) {
    //    printf("%f\n", outputs[i]);
    //}

    for (int i = 0; i < 200; i++) {
        double expected_outputs[10] = {0,0,0,0,0,0,0,0,0,0};
        int sample = randrange(0, 10);
        expectedOutputs(dt.dataPieces[sample].label, expected_outputs);
        trainNetwork(&nw, dt.dataPieces[sample].points, expected_outputs);
        logNetworkStdin(&nw);
        printf("%s\n", dt.dataPieces[sample].label);
        for (int j = 0; j < NUM_OUTPUT; j++) {
            printf("%f\n", outputs[j]);
        }
    }

    computeNetwork(&nw, dt.dataPieces[3].points, outputs);
    logNetworkStdin(&nw);
    printf("final model: %s\n", dt.dataPieces[69].label);
    for (int j = 0; j < NUM_OUTPUT; j++) {
        printf("%f\n", outputs[j]);
    }

    return 0;
}
