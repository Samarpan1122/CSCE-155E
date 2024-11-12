/**
 * Author:  Samarpan Mohanty
 *
 * Date: 2024-10-03
 */
#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include "utils.h"
#define R 6371


double degreesToRadians(double degree) {

    return ((degree * M_PI) / 180);
}

double getAirDistance(double originLatitude,double originLongitude,double destinationLatitude,double destinationLongitude) {
    if (originLatitude > 90 || originLatitude < -90 || destinationLatitude > 90 || destinationLatitude < -90 || originLongitude > 180 || originLongitude < -180 || destinationLongitude > 180 || destinationLongitude < -180) {
        printf("Invalid input: Latitude or Longitude not in range\n");
        exit(1);
    }
    return (acos(sin(degreesToRadians(originLatitude)) * sin(degreesToRadians(destinationLatitude)) + cos(degreesToRadians(originLatitude)) * cos(degreesToRadians(destinationLatitude)) * cos(degreesToRadians(destinationLongitude) - degreesToRadians(originLongitude))) * R);

}


double lorentzTimeDilation(double t, double percentC) {
    return t / sqrt(1 - pow(percentC, 2));
}
