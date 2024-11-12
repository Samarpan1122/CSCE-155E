/**
 *
 * Author: 	Samarpan Mohanty
 * Date: 	2024-09-19
 *
 * To compute a monthly savings table detailing the (inflation-adjusted) interest earned each month, contribution, and new balance
 */

#include <stdlib.h>
#include <stdio.h>
#include <math.h>

int main(int argc, char **argv) {

    double initialBalance = atof(argv[1]);
    double monthlyContribution = atof(argv[2]);
    double annualReturnRate = atof(argv[3]);
    double inflationRate = atof(argv[4]);
    int yearUntilRetirement = atoi(argv[5]);
    double totalInterest = 0;

    if (initialBalance < 0 || monthlyContribution < 0 || annualReturnRate < 0 || inflationRate < 0 || yearUntilRetirement < 0 || annualReturnRate > 1 || inflationRate > 1 || argc != 6) {
        printf("ERROR: one or more of your inputs is invalid\n");
        exit(1);
    }

    if (monthlyContribution * 12 > 18500) {
        printf("ERROR: monthly contributions exceed $18,500 annual limit\n");
        exit(1);
    }

    double monthsUntilRetirement = yearUntilRetirement * 12;

    double inflationAdjustedAnnualRate = (1 + annualReturnRate) / (1 + inflationRate) - 1;
    double inflationAdjustedMonthlyRate = inflationAdjustedAnnualRate / 12;

    printf("Month\tInterest\tBalance\n");

    for (int i = 1; i <= monthsUntilRetirement; i++) {
        double interest = round(initialBalance * inflationAdjustedMonthlyRate*100)/100;
        initialBalance = initialBalance + interest + monthlyContribution;
        totalInterest += interest;
        printf("%d \t$%0.2lf \t$%.2lf\n", i, interest, initialBalance);
    }

    printf("Total Interest Earned: $  %.2lf\n", totalInterest);
    printf("Final balance: %.2lf\n", initialBalance);


}
