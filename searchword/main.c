#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#define NUMBER_OF_BYTES 1000000000

int main(){

    char* string = (char*) malloc(NUMBER_OF_BYTES);

    if (string == NULL){
        return 0;
    }

    int counter=0;
    char *searchOfLexemes;
    char *delimiter = {" ,.-+/][)(#!%^&*?@№1234567890';:/\|<>~`"};

    printf("Enter string: ");

    gets(string);


    searchOfLexemes = strtok(string,delimiter);

    while (searchOfLexemes!=NULL){
          searchOfLexemes = strtok(NULL,delimiter);
          counter++;
    }

    printf("Words - %d\n", counter);

    free(string);

}


