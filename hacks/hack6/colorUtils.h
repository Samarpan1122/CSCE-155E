/**
 * Author:  Samarpan Mohanty
 *
 * Date: 2024-10-10
 */

/**
 * function to convert RGB to CMYK
 */
int rgbToCMYK(int r, int g, int b, double *c, double *m, double *y, double *k);

/**
 * function to convert CMYK to RGB
 */
int cmykToRGB(double c, double m, double y, double k, int *r, int *g, int *b);

