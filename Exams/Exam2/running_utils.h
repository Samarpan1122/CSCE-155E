/**
 * CSCE 155E - Fall 2024
 *
 * Exam 2
 * TODO: Author, date, purpose
 * Author: Samarpan Mohanty
 * Date: 2024-10-25
 * Purpose: This file contains the function prototypes for the  computing of statistics for users.
 */
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>

/**
 * This function converts a speed in kilometers per hour to miles per hour, feet per second, and meters per second.
 */
int convert(double kmsPerHours, double *milesPerHour, double *feetPerSecond, double *metersPerSecond);

/**
 * function that computes the total elevation gain given the elevationData points,
 * numPoints (number of elevation data points) and place the result in the pass-by-reference variable gain.
 */
int elevationGain(double *elevationData, int numPoints, double *gain);

/**
 *  function that converts a 2D array of elevation data from meters to feet.
 */
double **convertMap(double **elevationMap, int n, int m);
