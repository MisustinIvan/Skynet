#include <stdlib.h>
#include <stdio.h>
#include <dirent.h>
#include <string.h>
#include "main.h"

struct DataPiece{
    char * label;
    double points[NUM_POINTS];
};

struct Data{
    struct DataPiece dataPieces[NUM_SAMPLES];
};

void loadTrainingData(struct Data * data) {
    DIR * dir;
    struct dirent * ent;
    char * dir_path = "./Dataset/csv";

    if ((dir = opendir(dir_path)) != NULL) {
        int index = 0;
        // go over each item in the directory
        while ((ent = readdir(dir)) != NULL) {
            // skip those who start with .
            if (ent->d_type == DT_DIR || ent->d_name[0] == '.') {continue;}

            char file_path[256];
            sprintf(file_path, "%s/%s", dir_path, ent->d_name);

            char * label_str = strtok(ent->d_name, "_");
            
            FILE * fp = fopen(file_path, "r");
            if (fp == NULL) { printf("failed to read csv file"); continue; }
            
            int * points = malloc(sizeof(int) * NUM_POINTS);
            int i = 0;
            char p;
            while (i < NUM_POINTS && fscanf(fp, "%d%c", &points[i], &p) == 2) {
                if (p == ',') {
                    i++;
                }
            }

            for (int i = 0; i < NUM_POINTS; i++) {
                if (points[i] == 255) {points[i] = 0;}
                else if (points[i] == 0) {points[i] = 1;}
            }


            //for (int i = 0; i < NUM_POINTS; i++) {
            //    fscanf(fp, "%d", &points[i]);
            //}
            fclose(fp);
            struct DataPiece * dp = &data->dataPieces[index];
            dp->label = label_str;

            memcpy(dp->points, points, sizeof(int)*NUM_POINTS);
            free(points);
            index++;
        }
        closedir(dir);
        //printf("hopefully loaded\n");
    } else {
        printf("failed to open directory\n");
        exit(1);
    }

    for (int i = 0; i < NUM_SAMPLES; i++) {
        
    }
}

void expectedOutputs(char * label, double * outputs) {
    if (strcmp(label, "zero") == 0) { outputs[0] = 1; }
    if (strcmp(label, "one") == 0) { outputs[1] = 1; }
    if (strcmp(label, "two") == 0) { outputs[2] = 1; }
    if (strcmp(label, "three") == 0) { outputs[3] = 1; }
    if (strcmp(label, "four") == 0) { outputs[4] = 1; }
    if (strcmp(label, "five") == 0) { outputs[5] = 1; }
    if (strcmp(label, "six") == 0) { outputs[6] = 1; }
    if (strcmp(label, "seven") == 0) { outputs[7] = 1; }
    if (strcmp(label, "eight") == 0) { outputs[8] = 1; }
    if (strcmp(label, "nine") == 0) { outputs[9] = 1; }
}
