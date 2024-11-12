/**
 * Author: Samarpan Mohanty
 * Date: 2024-11-02
 *
 * This file contains the functions for string utility functions.
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "string_utils.h"

void replaceChar(char *s, char oldChar, char newChar) {
    if (s == NULL) return;
    while (*s != '\0') {
        if (*s == oldChar) {
            *s = newChar;
        }
        s++;
    }
}

char *replaceCharCopy(const char *s, char oldChar, char newChar) {
    if (s == NULL) return NULL;

    char *newString = malloc(strlen(s) + 1);
    if (newString == NULL) {
        perror("Failed to allocate memory");
        return NULL;
    }

    char *ptr = newString;
    while (*s != '\0') {
        *ptr = (*s == oldChar) ? newChar : *s;
        ptr++;
        s++;
    }
    *ptr = '\0';
    return newString;
}

void removeChar(char *s, char c) {
    if (s == NULL) return;

    char *src = s, *dst = s;
    while (*src != '\0') {
        if (*src != c) {
            *dst = *src;
            dst++;
        }
        src++;
    }
    *dst = '\0';
}

char *removeCharCopy(const char *s, char c) {
    if (s == NULL) return NULL;

    int len = strlen(s);
    char *newString = malloc(len + 1);
    if (newString == NULL) {
        perror("Failed to allocate memory");
        return NULL;
    }

    char *ptr = newString;
    while (*s != '\0') {
        if (*s != c) {
            *ptr = *s;
            ptr++;
        }
        s++;
    }
    *ptr = '\0';
    return newString;
}

char **lengthSplit(const char *s, int n) {
    if (s == NULL || n <= 0) {
        fprintf(stderr, "Invalid input string or length.\n");
        return NULL;
    }

    int strLen = strlen(s);
    int numChunks = (strLen + n - 1) / n;

    char **result = malloc(numChunks * sizeof(char *));
    if (result == NULL) {
        perror("Failed to allocate memory for result array");
        return NULL;
    }

    for (int i = 0; i < numChunks; i++) {
        int len = (i * n + n < strLen) ? n : strLen - i * n;
        result[i] = malloc(len + 1);
        if (result[i] == NULL) {
            perror("Failed to allocate memory for chunk");
            for (int j = 0; j < i; j++) free(result[j]);
            free(result);
            return NULL;
        }
        strncpy(result[i], s + i * n, len);
        result[i][len] = '\0';
    }
    return result;
}
//make a function that takes a string and a character and returns the number of times that character appears in the string
int countChar(const char *s, char c) {
    if (s == NULL) return 0;

    int count = 0;
    while (*s != '\0') {
        if (*s == c) {
            count++;
        }
        s++;
    }
    return count;
}



