/**
 *
 * Author: Samarpan Mohanty
 *
 * Date: 2024-09-27
 *
 * This program reads 3 cordinates from user by needing 6 numbers and then calculate distance between each cordiantes. then it will show the points with least distance.
 *
 */
#include <stdlib.h>
#include <stdio.h>
#include <math.h>

int main(int argc, char **argv) {

    if (argc != 7) {
        printf("Error: Only 6 numbers are needed\n");
        exit(1);
    }
    double x1 = atof(argv[1]);
    double y1 = atof(argv[2]);
    double x2 = atof(argv[3]);
    double y2 = atof(argv[4]);
    double x3 = atof(argv[5]);
    double y3 = atof(argv[6]);

    double distanceAB = sqrt(pow(x1 - x2, 2) + pow(y1 - y2, 2));
    double distanceBC = sqrt(pow(x2 - x3, 2) + pow(y2 - y3, 2));
    double distanceCA = sqrt(pow(x1 - x3, 2) + pow(y1 - y3, 2));

    printf("Distance ab: %.6lf\n", distanceAB);
    printf("Distance ac: %.6lf\n", distanceCA);
    printf("Distance bc: %.6lf\n", distanceBC);


    double minDistance = distanceAB;

    if (distanceBC < minDistance) {
        minDistance = distanceBC;
        printf("Closest two points: bc\n");
    }
    if (distanceCA < minDistance) {
        minDistance = distanceCA;
        printf("Closest two points: ac\n");
    }
    if (distanceAB == minDistance) {
        printf("Closest two points: ab\n");
    }

    return 0;
}
