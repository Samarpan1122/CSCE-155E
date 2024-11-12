/**
 * Samarpan Mohanty
 *
 * 2024-09-04
 *
 * this programs calculates roots of quadratic equation
 * reads 3 coefficients from user
 * calculates roots
 */

#include <stdlib.h>
#include <stdio.h>
#include <math.h>

int main(int argc, char **argv) {

    double a,b,c;
    double root1, root2;

    scanf("%lf", &a);
    scanf("%lf", &b);
    scanf("%lf", &c);

    root1 = (-b + sqrt(b*b - 4*a*c))/ (double) (2*a);
    root2 = (-b - sqrt(b*b - 4*a*c))/ (double) (2*a);

    printf("Roots are: %.2lf and %.2lf\n", root1, root2);

    return 0;

}
