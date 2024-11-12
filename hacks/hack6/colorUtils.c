#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include "colorUtils.h"

int rgbToCMYK(int r, int g, int b, double *c, double *m, double *y, double *k) {
    // Check for NULL pointers
    if (c == NULL || m == NULL || y == NULL || k == NULL) {
        printf("Error: One or more output pointers are NULL.\n");
        return 2;  // Error code for NULL pointers
    }

    // Check for valid RGB input values
    if (r < 0 || r > 255 || g < 0 || g > 255 || b < 0 || b > 255) {
        printf("Invalid input: RGB values not in range\n");
        return 1;
    }

    // Convert RGB to the range [0, 1]
    double r_prime = r / 255.0;
    double g_prime = g / 255.0;
    double b_prime = b / 255.0;

    // Calculate K value
    *k = 1 - fmax(fmax(r_prime, g_prime), b_prime);

    // Special case for black (when K = 1)
    if (*k == 1.0) {
        *c = 0;
        *m = 0;
        *y = 0;
        return 0;
    }

    // Calculate C, M, Y values
    *c = (1 - r_prime - *k) / (1 - *k);
    *m = (1 - g_prime - *k) / (1 - *k);
    *y = (1 - b_prime - *k) / (1 - *k);

    return 0;
}

int cmykToRGB(double c, double m, double y, double k, int *r, int *g, int *b) {
    // Check for NULL pointers
    if (r == NULL || g == NULL || b == NULL) {
        printf("Error: One or more output pointers are NULL.\n");
        return 2;  // Error code for NULL pointers
    }

    // Input range check for CMYK
    if (c < 0 || c > 1 || m < 0 || m > 1 || y < 0 || y > 1 || k < 0 || k > 1) {
        printf("Invalid input: CMYK values not in range\n");
        return 1;
    }

    // Convert CMYK to RGB with rounding
    *r = round(255 * (1 - c) * (1 - k));
    *g = round(255 * (1 - m) * (1 - k));
    *b = round(255 * (1 - y) * (1 - k));

    return 0;
}
