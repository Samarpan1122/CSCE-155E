/**
 * Author: Samarpan Mohanty
 * Date: 2024-11-02
 *
 * This file contains the test cases for the string utility functions.
 */
#include <stdio.h>
#include <stdlib.h>
#include "string_utils.h"

void test_replaceChar() {
    char s[] = "hello world";
    replaceChar(s, 'o', '0');
    printf("replaceChar: %s\n", s);
}

void test_replaceCharCopy() {
    const char *s = "hello world";
    char *result = replaceCharCopy(s, 'o', '0');
    if (result) {
        printf("replaceCharCopy: %s\n", result);
        free(result);
    } else {
        printf("replaceCharCopy: Memory allocation failed.\n");
    }
}

void test_removeChar() {
    char s[] = "hello world";
    removeChar(s, 'o');
    printf("removeChar: %s\n", s);
}

void test_removeCharCopy() {
    const char *s = "hello world";
    char *result = removeCharCopy(s, 'o');
    if (result) {
        printf("removeCharCopy: %s\n", result);
        free(result);
    } else {
        printf("removeCharCopy: Memory allocation failed.\n");
    }
}

void test_lengthSplit() {
    const char *s = "hello world!";
    char **result = lengthSplit(s, 3);

    if (result != NULL) {
        printf("lengthSplit:\n");
        for (int i = 0; result[i] != NULL; i++) {
            printf("  Chunk %d: %s\n", i, result[i]);
            free(result[i]);
        }
        free(result);
    } else {
        printf("lengthSplit: Invalid input or memory allocation failed.\n");
    }
}

int main() {
    test_replaceChar();
    test_replaceCharCopy();
    test_removeChar();
    test_removeCharCopy();
    test_lengthSplit();

    return 0;
}
