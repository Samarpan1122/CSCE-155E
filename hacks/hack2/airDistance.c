/**
 * Samarpan Mohanty
 *
 * 2024-09-05
 *
 * program to calculate distance between 2 points on earth
 * user inputs longitude and latitude of 2 location in degrees
 * degrees converted to radians
 * then distance calculated with formula
 *
 */

#include <stdlib.h>
#include <stdio.h>
#include <math.h>

int main(int argc, char **argv) {

    double long1, lat1, long2, lat2, distance, radiusOfEarth;

    radiusOfEarth = 6371.0;

    printf( "Enter latitude of first location: ");
    scanf("%lf", &lat1);
    printf( "\nEnter longitude of first location: ");
    scanf("%lf", &long1);
    printf( "\nEnter latitude of second location: ");
    scanf("%lf", &lat2);
    printf( "\nEnter longitude of second location: ");
    scanf("%lf", &long2);


    if (!(lat1<=90 && lat1>=-90 && lat2<=90 && lat2>=-90 && long1<=180 && long1>=-180 && long2<=180 && long2>=-180)) {
        printf("Invalid input\n");
        exit(1);
    }

    printf("\nLocation Distance\n");
    printf("========================\n");
    printf("Origin:      (%lf, %lf)\n", lat1, long1);
    printf("Destination: (%lf, %lf)\n", lat2, long2);


    long1 = long1 * M_PI / 180.0;
    lat1 = lat1 * M_PI / 180.0;
    long2 = long2 * M_PI / 180.0;
    lat2 = lat2 * M_PI / 180.0;

    distance = radiusOfEarth * acos(sin(lat1) * sin(lat2) + cos(lat1) * cos(lat2) * cos(long1 - long2));

    printf("Air distance is %lf kms\n", distance);






    return 0;

}



