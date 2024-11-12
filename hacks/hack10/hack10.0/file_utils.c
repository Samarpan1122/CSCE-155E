/**
 * Author: Samarpan Mohanty
 * Date : 2024-11-10
 *
 * This file contains the function definitions for the functions that are declared in file_utils.h
 */
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "file_utils.h"

char *getFileContents(const char *filePath) {
    if (filePath == NULL) {
        return NULL;
    }

    FILE *file = fopen(filePath, "r");
    if (file == NULL) {
        return NULL;
    }

    if (fseek(file, 0, SEEK_END) != 0) {
        fclose(file);
        return NULL;
    }

    long fileSize = ftell(file);
    if (fileSize < 0) {
        fclose(file);
        return NULL;
    }
    rewind(file);

    if (fileSize == 0) {
        fclose(file);
        return strdup(""); 
    }

    char *content = (char *)malloc((fileSize + 1) * sizeof(char));
    if (content == NULL) {
        fclose(file);
        return NULL;
    }

    size_t bytesRead = fread(content, sizeof(char), fileSize, file);
    if (bytesRead < fileSize) {
        free(content);
        fclose(file);
        return NULL;
    }
    content[fileSize] = '\0';

    fclose(file);
    return content;
}

char **getFileLines(const char *filePath, int *numLines) {
    if (filePath == NULL || numLines == NULL) {
        if (numLines != NULL) {
            *numLines = 0;
        }
        return NULL;
    }

    FILE *file = fopen(filePath, "r");
    if (file == NULL) {
        *numLines = 0;
        return NULL;
    }

    char **lines = NULL;
    char buffer[2001];
    *numLines = 0;

    while (fgets(buffer, sizeof(buffer), file)) {
        buffer[strcspn(buffer, "\n")] = '\0';

        char *line = strdup(buffer);
        if (line == NULL) {
            for (int i = 0; i < *numLines; i++) {
                free(lines[i]);
            }
            free(lines);
            fclose(file);
            *numLines = 0;
            return NULL;
        }

        char **temp = (char **)realloc(lines, (*numLines + 1) * sizeof(char *));
        if (temp == NULL) {
            free(line);
            for (int i = 0; i < *numLines; i++) {
                free(lines[i]);
            }
            free(lines);
            fclose(file);
            *numLines = 0;
            return NULL;
        }

        lines = temp;
        lines[*numLines] = line;
        (*numLines)++;
    }

    fclose(file);

    if (*numLines == 0) {
        return NULL;
    }

    return lines;
}
