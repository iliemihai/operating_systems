#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <stdbool.h>
#include "stdint.h"
#include <ctype.h>

// total number of lines, words, chars (if multiple files are input)
static uintmax_t total_lines, total_words, total_chars;
void wc(FILE *infile, char *inname);

int main(int argc, char *argv[]) {
    if(argc > 1) {

        int i;
        for(i=1; i<argc; i++) {
          FILE* fd = fopen(argv[i], "r");
          if( fd == NULL) {
            printf("Error opening file %s!\n", argv[i]);
            return 0;
          }
          wc(fd, argv[i]);
        }
        if(argc > 2) { // print totals for multiple files
            printf("%7ld %7ld %7ld   %s\n",  total_lines, total_words, total_chars, "total");
        }

    } else {

        wc(stdin, "INPUT");
    }

    return 0;
}


void wc(FILE *infile, char *inname) {
    uintmax_t lines = 0, words = 0, chars = 0;

    char buff;

    while( (buff = fgetc(infile)) != EOF) {
        chars ++;
        if (buff == ' ')
          words++;
        else if(buff == '\n')
          lines++;
    }


    total_lines += lines;
    total_words += words;
    total_chars += chars;

    printf("%7ld %7ld %7ld   %s\n",  lines, words, chars, inname);
}
