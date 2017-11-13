#include <stdio.h>
#include <stdlib.h>
#include "string.h"
#define ENG_LETTERS 26

char* getInputString(int size){
    char *array = (char*) malloc(size);
    printf("Enter string:");
    gets(array);
    return array;
}

void encrypt (char* keyword, unsigned char* stringArray, char* alphabet){
    int k=0;

    for( int i = 1;i <=26 ;i++){

        for(int j = 0; j < strlen(keyword); j++){

            if(keyword[j] == alphabet[i]){

                if ((stringArray[k] >= 'a') && (stringArray[k] <= 'z')){

                    stringArray[k] = stringArray[k] + ( i % ENG_LETTERS);

                    if (stringArray[k] > 'z'){
                        stringArray[k] = 'a' + (stringArray[k] - 'z') - 1;
                   }
                }
                k++;
            }
        }
    }
}

void decrypt(char* keyword, unsigned char* stringArray,char* alphabet){
    int k=0;

    for( int i = 0;i <=26 ;i++){

        for(int j = 0; j < strlen(keyword); j++){

            if(keyword[j] == alphabet[i]){

                if ((stringArray[k] >= 'a') && (stringArray[k] <= 'z')){

                    stringArray[k] = stringArray[k] - (i % ENG_LETTERS);

                    if (stringArray[k] > 'z'){
                        stringArray[k] = 'a' + (stringArray[k] - 'z') - 1;

                    }
                }
                k++;
            }
        }
    }
}

void userChoice(int selector, unsigned char* stringArray, char* keyword,char* abetka){
    const int ENCRYPT = 1;
    const int DECRYPT = 2;

    if(selector == ENCRYPT){

        encrypt(keyword, stringArray, abetka);

        for(int i = 0; i < strlen(stringArray); i++){
            printf("%c", stringArray[i]);
        }
    }

    if(selector == DECRYPT){

        decrypt(keyword, stringArray,abetka);

        for(int i = 0; i < strlen(stringArray); i++){
            printf("%c", stringArray[i]);
        }
    }
}

int main() {
    unsigned char* stringArray = getInputString(10000000);
    int selector;
    char keyword[26];
    char alphabet[27] = {0,'a','b','c','d','e','f','g','h','i','j','k','l', 'm','n','o','p','q','r','s','t','u','v','w','x','y','z'};
    printf("Enter a keyword that matches the string for encryption or decryption by length:");
    gets(keyword);

    printf("If you want to encrypt this string enter (1), if you want to decrypt enter (2): ");
    scanf("%d", &selector);

    userChoice(selector, stringArray, keyword, alphabet);

    free(stringArray);

    return 0;
}






