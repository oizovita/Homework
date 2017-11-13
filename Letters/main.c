#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#define NUMBER_OF_BYTES 1000000000
#define NUMBER_OF_LETTERS 26
#define LENGTH_OF_STRING 1000000

int main(){
    int counter;
    int sortingNumbers;
    int counterOfLetters = 0;
    int numbersArray[NUMBER_OF_LETTERS]={0};
    char sortingLetters;
    char string[LENGTH_OF_STRING];
    char wordArray[NUMBER_OF_LETTERS]={0};

    printf("Enter string: ");
    gets(string);

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
            counterOfLetters++;
            printf("%c-%d\n",i,counter);
        }
    }

    printf("\n");

    for(int i = 0;i < NUMBER_OF_LETTERS;i++){

        for(int k = 0;k < NUMBER_OF_LETTERS - i;k++){

            if(numbersArray[k] < numbersArray[k+1]){
                sortingNumbers = numbersArray[k];
                sortingLetters = wordArray[k];
                numbersArray[k] = numbersArray[k+1];
                wordArray[k] = wordArray[k+1];
                numbersArray[k+1] = sortingNumbers;
                wordArray[k+1] = sortingLetters;
            }
        }
    }

    for(int k = 0;k < counterOfLetters;k++){
        printf("%c-%d\n",wordArray[k],numbersArray[k]);
    }
}

























