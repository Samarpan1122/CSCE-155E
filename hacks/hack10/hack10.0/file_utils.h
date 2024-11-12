/**
 * Author: Samarpan Mohanty
 * Date : 2024-11-10
 *
 * This file contains the function prototypes for the functions that are defined in file_utils.c
 */

/**
 * a function that, given a file path/name as a string opens the file and returns its entire contents as a single string. Any endline characters should be preserved.
 */
char *getFileContents(const char *filePath);

/**
 * a function that, given a file path/name as a string opens the file and returns the contents of the file as an array of strings. Each element in the array should correspond to a line in the file. Any end line character should be chomped out and not included. The size of the resulting array of strings needs to be communicated to the calling function using the pass-by-reference numLines parameter (it is not input).
 */
char **getFileLines(const char *filePath, int *numLines);
