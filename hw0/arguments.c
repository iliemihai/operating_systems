#include <stdio.h>
#include <string.h>

int main(int argc, char *argv[]) {
    // TODO: Print the program name
    printf("Program name: %s\n", argv[0]);
    int i;
    printf("Arguments: ");
    // TODO: Print all the arguments given to the program.
    //
    //       Separate multiple arguments using commas on one line.
    //       e.g. "Arguments: arg1,arg2,arg3"
    //
    //       Print "NONE" if no arguments are present.
    /*COMPLETE HERE*/
    if (argc > 1) {
        for (i=1; i<argc; i++)
            printf("%s ", argv[i]);
        printf("\n");
    } else {
        printf("None\n"); 
    }

    return 0;
}
