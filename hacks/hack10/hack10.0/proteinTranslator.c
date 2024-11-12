/**
 * Author: Samarpan Mohanty
 * Date : 2024-11-10
 *
 * This program reads a DNA sequence from a file, translates it into a protein sequence, and writes the protein sequence to an output file.
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "file_utils.h"
#include "protein_utils.h"

int isValidNucleotide(char c) {
    return (c == 'A' || c == 'T' || c == 'C' || c == 'G');
}

void replaceThymineWithUracil(char *rna) {
    for (int i = 0; i < strlen(rna); i++) {
        if (rna[i] == 'T') {
            rna[i] = 'U';
        }
    }
}

int main(int argc, char **argv) {
    if (argc != 3) {
        fprintf(stderr, "Usage: %s <input file> <output file>\n", argv[0]);
        return 1;
    }

    char *dna = getFileContents(argv[1]);
    if (dna == NULL) {
        fprintf(stderr, "Error: Failed to read DNA sequence from input file\n");
        return 1;
    }

    FILE *output = fopen(argv[2], "w");
    if (output == NULL) {
        fprintf(stderr, "Error: Unable to open output file %s\n", argv[2]);
        free(dna);
        return 1;
    }

    char rna[4] = {'\0'};
    int index = 0;

    for (int i = 0; i < strlen(dna); i++) {
        if (isspace(dna[i])) {
            continue;
        }

        if (!isValidNucleotide(dna[i])) {
            fprintf(stderr, "Error: Invalid nucleotide character '%c' at position %d\n", dna[i], i);
            free(dna);
            fclose(output);
            return 1;
        }

        char nucleotide = dna[i] == 'T' ? 'U' : dna[i];
        rna[index++] = nucleotide;

        if (index == 3) {
            if (strcmp(rna, "UAA") == 0 || strcmp(rna, "UAG") == 0 || strcmp(rna, "UGA") == 0) {
                break;
            }

            char protein = rnaToProtein(rna);
            if (protein == '\0') {
                fprintf(stderr, "Error: Invalid trigram '%s' at position %d\n", rna, i - 2);
                free(dna);
                fclose(output);
                return 1;
            }

            fputc(protein, output);
            index = 0;
        }
    }

    if (index != 0) {
        fprintf(stderr, "Warning: Incomplete trigram at the end of the sequence\n");
    }

    free(dna);
    fclose(output);
    fprintf(stdout, "Protein translation completed successfully.\n");
    return 0;
}
