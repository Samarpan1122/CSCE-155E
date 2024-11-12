/**
 * Author:  Samarpan Mohanty
 *
 * Date: 2024-10-03
 */

/**
 * This program performs several ad-hoc unit
 * tests on the color utils library.
 */
#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include "utils.h"
#define DELTA 1

double expectedD, actualD, timeDialationExpected, timeDialationActual;
int passed = 0, failed = 0;
double lat1, lon1, lat2, lon2, time, percentC;

int main(int argc, char **argv) {

    lat1 = 32.7767;
    lon1 = -96.7970;
    lat2 = 29.7604;
    lon2 = -95.3698;
    printf("Testing getAirDistance(%f, %f, %f, %f)\t", lat1, lon1, lat2, lon2);
    actualD = getAirDistance(lat1, lon1, lat2, lon2);
    expectedD = 361.7;
    if(fabs(expectedD - actualD) > DELTA) {
        printf("FAILED: returned %f, expected %f\n", actualD, expectedD);
        failed++;
    } else {
        printf("PASSED\n");
        passed++;
    }

    lat1 = 25.7617;
    lon1 = -80.1918;
    lat2 = 34.0522;
    lon2 = -118.2437;
    printf("Testing getAirDistance(%f, %f, %f, %f)\t", lat1, lon1, lat2, lon2);
    actualD = getAirDistance(lat1, lon1, lat2, lon2);
    expectedD = 3758.3;
    if(fabs(expectedD - actualD) > DELTA) {
        printf("FAILED: returned %lf, expected %lf\n", actualD, expectedD);
        failed++;
    } else {
        printf("PASSED\n");
        passed++;
    }

    lat1 = 40.7128;
    lon1 = -74.0060;
    lat2 = 34.0522;
    lon2 = -118.2437;
    printf("Testing getAirDistance(%f, %f, %f, %f)\t", lat1, lon1, lat2, lon2);
    actualD = getAirDistance(lat1, lon1, lat2, lon2);
    expectedD = 3935.2;
    if(fabs(expectedD - actualD) > DELTA) {
        printf("FAILED: returned %f, expected %f\n", actualD, expectedD);
        failed++;
    } else {
        printf("PASSED\n");
        passed++;
    }

    time = 25.562603;
    percentC = 0.116812;
    printf("Testing lorentzTimeDilation(%f, %f)\t", time, percentC);
    timeDialationActual = lorentzTimeDilation(time, percentC);
    timeDialationExpected = 25.738810;
    if(fabs(timeDialationExpected - timeDialationActual) > DELTA) {
        printf("FAILED: returned %f, expected %f\n", timeDialationActual, timeDialationExpected);
        failed++;
    } else {
        printf("PASSED\n");
        passed++;
    }

    time = 2.3;
    percentC = 0.7;
    printf("Testing lorentzTimeDilation(%f, %f)\t", time, percentC);
    timeDialationActual = lorentzTimeDilation(time, percentC);
    timeDialationExpected = 2.6;
    if(fabs(timeDialationExpected - timeDialationActual) > DELTA) {
        printf("FAILED: returned %f, expected %f\n", timeDialationActual, timeDialationExpected);
        failed++;
    } else {
        printf("PASSED\n");
        passed++;
    }

    time = 3.5;
    percentC = 0.1;
    printf("Testing lorentzTimeDilation(%f, %f)\t", time, percentC);
    timeDialationActual = lorentzTimeDilation(time, percentC);
    timeDialationExpected = 3.5;
    if(fabs(timeDialationExpected - timeDialationActual) > DELTA) {
        printf("FAILED: returned %f, expected %f\n", timeDialationActual, timeDialationExpected);
        failed++;
    } else {
        printf("PASSED\n");
        passed++;
    }

    printf("Number Test Cases Passed: %6d\n", passed);
    printf("Number Test Cases Failed: %6d\n", failed);
    printf("Percent Passed:           %6.2f\n", 100.0 * passed / (passed + failed));

    return 0;

}
