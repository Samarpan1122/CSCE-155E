/**
 * Samarpan Mohanty
 *
 * 2024-09-11
 *
 * An application for the company to help customers track their mobile data usage.
 * argumenents are:
 ** Number of GB in the plan per 30 day period
 ** The current day in the 30 day period (in the range 1, first day, 30 for the last day)
 ** The total number of GB used so far
 * program should then compute whether the customer is over, under, or right on the average daily usage of their plan. It should also inform them of how many GB are left and how many, on average, they can use per day for the rest of the 30 day period
 */

#include <stdlib.h>
#include <stdio.h>
#include <math.h>

int main(int argc, char **argv) {
    double planGB, usedGB, avgDailyUsage, idealAvgDailyUsage,remainingGB, avgDailyRemaining;
    int currentDay;

    if (argc != 4) {
        printf("ERROR \n");
        exit(1);
    }

    planGB = atof(argv[1]);
    currentDay = atoi(argv[2]);
    usedGB = atof(argv[3]);

    if (currentDay < 1 || currentDay > 30) {
        printf("ERROR \n");
        exit(1);
    }
    if (planGB < 0 || usedGB < 0) {
        printf("ERROR \n");
        exit(1);
    }

    avgDailyUsage = usedGB / (double) currentDay;
    idealAvgDailyUsage = planGB / 30.0;
    remainingGB = planGB - usedGB;
    avgDailyRemaining = remainingGB / (30 - currentDay);

    printf("%d days used, %d days remaining\n", currentDay, 30 - currentDay);
    printf("Average daily use: %.3lf GB/day\n", avgDailyUsage);

    if (avgDailyRemaining < 0) {
        printf("You have already met your limit for this month. Looks like you're getting some overage charges...\n");
    } else if (avgDailyUsage > idealAvgDailyUsage) {
        printf("You are EXCEEDING your average daily use (%.3lf GB/day).\n", idealAvgDailyUsage);
        printf("Continuing this high usage, you'll exceed your data plan by %.3lf GB.\n", avgDailyUsage * 30 - planGB);
        printf("To stay below your data plan, use no more than %.3lf GB/day.\n", avgDailyRemaining);
    }  else if (avgDailyUsage < idealAvgDailyUsage) {
        printf("You are at or below your average daily use (%.3lf GB/day).\n", idealAvgDailyUsage);
        printf("You can use up to %.3lf GB/day and stay below your data plan limit.\n", avgDailyRemaining);
    }
    
    return 0;
}
