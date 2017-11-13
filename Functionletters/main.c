#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#define NUMBER_OF_LETTERS 26
#define LENGTH_OF_STRING 1000000


char* getInputString(int size){
    char *array = (char*) malloc(size);
    printf("Enter string:");
    gets(array);
    return array;

}

void swapInt(int *xp, int *yp){
    int temp = *xp;
    *xp = *yp;
    *yp = temp;
}

void swapChar(char *xp, char *yp){
    int temp = *xp;
    *xp = *yp;
    *yp = temp;
}


void sort(char *wordArray,int  *numbersArray){

    for(int i = 0; i < NUMBER_OF_LETTERS; i++){

        for(int k = 0; k < NUMBER_OF_LETTERS - i; k++){

            if(numbersArray[k] < numbersArray[k+1]){
                swapInt(&numbersArray[k],&numbersArray[k+1]);
                swapChar(&wordArray[k],&wordArray[k+1]);
            }
        }
    }
}

void show(char* wordArray, int *numbersArray ){

    for(int k = 1;k < strlen(wordArray);k++){
        printf("%c-%d\n",wordArray[k],numbersArray[k]);
    }
}

void letter(char *string, char* wordArray, int* numbersArray){

    int counter;

    for( int k = 0 ,i = 'a';i <= 'z';i++,k++){

        counter = 0;

        for(int j = 0; j < strlen(string); j++){

            if(string[j] == i){
                counter++;
            }

        }

        if(counter > 0){
            wordArray[k] = i;
            numbersArray[k] = counter;

            printf("%c-%d\n",i,counter);
        }
    }

}

int main(){

    int numbersArray[NUMBER_OF_LETTERS]={0};
    char *string= getInputString(100000000000);
    char wordArray[NUMBER_OF_LETTERS]={0};

    letter(string,wordArray,numbersArray);
    sort(wordArray,numbersArray);
    printf("\n");
    show(wordArray,numbersArray);

    free(string);
}




























