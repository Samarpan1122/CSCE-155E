/**
 *
 * Author: Samarpan Mohanty
 *
 * Date: 2024-09-27
 *
 * program that takes, as command line arguments, the initial population,geometric rate and arithmetic rate and outputs a table of how the population will increase year to year along with an average of the two models until the average population has doubled from the initial population.
 *
 */

#include <stdlib.h>
#include <stdio.h>
#include <math.h>

int main(int argc, char **argv) {

    if (argc != 4) {
        printf("Error: Only 3 numbers are needed\n");
        exit(1);
    }
    if (atoi(argv[1]) <= 0) {
        printf("Error: Initial population cannot be negative\n");
        exit(1);
    }
    int initialPopulation = atoi(argv[1]);
    double geometricRate = atof(argv[2]);
    int arithmeticRate = atoi(argv[3]);

    printf("Initial Population: %d\n", initialPopulation);
    int year = 1;
    printf("Year\tGeometric  Arithmetic  Average\n");
    printf("-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-\n");

    double geometricPopulation = round((initialPopulation * geometricRate) + initialPopulation);
    int arithmeticPopulation = initialPopulation + arithmeticRate;
    double averagePopulation = round((geometricPopulation + arithmeticPopulation) / 2.0);

    while (averagePopulation < (2 * initialPopulation)) {
        printf("%d\t%.0lf\t%d\t%.0lf\n", year, geometricPopulation, arithmeticPopulation, averagePopulation);
        geometricPopulation = round((geometricPopulation * geometricRate) + geometricPopulation);
        arithmeticPopulation = arithmeticPopulation + arithmeticRate;
        averagePopulation = round((geometricPopulation + arithmeticPopulation) / 2);
        year++;
    }
    printf("%d\t%.0lf\t%d\t%.0lf\n", year, geometricPopulation, arithmeticPopulation, averagePopulation);
    return 0;
}


