/**
 * Author:  Samarpan Mohanty
 *
 * Date: 2024-10-03
 */



/**
 * function to convert degrees to radians
 */
double degreesToRadians(double degree);



/**
 * function to calculate the distance between two points
 */
double getAirDistance(double originLatitude,
                      double originLongitude,
                      double destinationLatitude,
                      double destinationLongitude);


/**
 * function to calculate the time dilation
 * due to the lorentz contraction
 */

double lorentzTimeDilation(double t, double percentC);
