#include <stdio.h>
#include <stdlib.h>
#include "string.h"

char* getInputString(int size){
    char *array = (char*) malloc(size + 1);
    printf("Enter string:");
    gets(array);
    return array;
    free(array);
}

int countWords(char* stringArray){
    const char *SEPARATORS = {"|!?.,;/*-+{}[]\'@#$%^&()=~1234567890<>№_` "};
    char* str;
    int count = 0;

    str = strtok(stringArray, SEPARATORS);

    while (str != NULL) {

        count++;
        str = strtok(NULL, SEPARATORS);
    }

    printf("Number of words - %d\n", count);
}

int main() {

    char* stringArray = getInputString(10000000);
    countWords(stringArray);

    return 0;
}

