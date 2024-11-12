/**
 * Author: Samarpan Mohanty
 * Date: 2024-11-02
 *
 * This file contains the function prototypes for string utility functions.
 */

// Replaces all instances of oldChar with newChar in the string s.
void replaceChar(char *s, char oldChar, char newChar);

// Returns a new string with all instances of oldChar replaced by newChar.
char *replaceCharCopy(const char *s, char oldChar, char newChar);

// Removes all instances of the character c from the string s.
void removeChar(char *s, char c);

// Returns a new string with all instances of the character c removed.
char *removeCharCopy(const char *s, char c);

// Splits the string s into an array of strings, each of length n.
char **lengthSplit(const char *s, int n);
