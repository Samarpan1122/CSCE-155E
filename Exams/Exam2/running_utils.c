/**
 * CSCE 155E - Fall 2024
 *
 * Exam 2
 * TODO: Author, date, purpose
 * Author: Samarpan Mohanty
 * Date: 2024-10-25
 * Purpose: This file contains the functions for the computing of statistics for users.
 */

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>
#include "running_utils.h"

int convert(double kmsPerHour, double *milesPerHour, double *feetPerSecond, double *metersPerSecond) {
    if (kmsPerHour < 0) {
        printf("Error: Speed cannot be negative\n");
        return 1;
    }
        if (milesPerHour == NULL || feetPerSecond == NULL || metersPerSecond == NULL) {
            printf("Error: Null pointer detected\n");
            return 1;
        }
    *milesPerHour = kmsPerHour * 0.621371;
    *feetPerSecond = kmsPerHour * 0.911344;
    *metersPerSecond = kmsPerHour * 0.277777;
    return 0;
}

int elevationGain(double *elevationData, int numPoints, double *gain) {
    if (elevationData == NULL || gain == NULL) {
        printf("Error: Null pointer detected\n");
        return 1;
    }
    if (numPoints <= 0) {
        printf("Error: Invalid number of points provided to elevationGain function.\n");
        return 1;
    }
    *gain = 0.0;
    for(int i=1; i<numPoints; i++) {
        if(elevationData[i] > elevationData[i-1]) {
        *gain += elevationData[i] - elevationData[i-1];
        }
    }
    return 0;
}

double **convertMap(double **elevationMap, int n, int m) {
    if (elevationMap == NULL) {
        printf("Error: Null pointer detected\n");
        return NULL;
    }
    if (n <= 0 || m <= 0) {
        printf("Error: Invalid number of rows or columns provided to convertMap function.\n");
        return NULL;
    }
    double **converted = (double **) malloc(sizeof(double *) * n);

    for(int i=0; i<n; i++) {
        converted[i] = (double *) malloc(sizeof(double) * m);
        for(int j=0; j<m; j++) {
        converted[i][j] = elevationMap[i][j] * 3.28084;
        }
    }
    return converted;
}


