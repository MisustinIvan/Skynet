#include <stdlib.h>
#include <stdio.h>
#include <dirent.h>
#include <string.h>
#include "main.h"
#ifndef DATA_H
#define DATA_H
struct DataPiece{
    char * label;
    double points[NUM_POINTS];
};

struct Data{
    struct DataPiece dataPieces[NUM_SAMPLES];
};
void loadTrainingData(struct Data * data);

void expectedOutputs(char * label, double * outputs);
#endif
