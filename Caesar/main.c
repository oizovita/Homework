#include <stdio.h>
#include <stdlib.h>
#include "string.h"
#define ENG_LETTERS 26

void encrypt (int key, unsigned char* stringArray){

    int strLen = strlen(stringArray);

    for(int i = 0; i < strLen; i++){


        if ((stringArray[i] >= 'a') && (stringArray[i] <= 'z')){

            stringArray[i] = stringArray[i] + (key % ENG_LETTERS) ;

            if (stringArray[i] > 'z'){
                stringArray[i] = 'a' + (stringArray[i] - 'z') - 1;

            }
        }
    }
}

void decrypt(int key, unsigned char* stringArray){

    int strLen = strlen(stringArray);

    for(int i = 0; i < strLen; i++){


        if (stringArray[i] >= 'a' && stringArray[i] <= 'z'){
            stringArray[i] = stringArray[i] - (key % ENG_LETTERS) ;

            if (stringArray[i] < 'a') {
                stringArray[i] = 'z' - ('a' - stringArray[i]) + 1;

            }
        }
    }
}

void userChoice(int selector, unsigned char* stringArray, int key){
    const int ENCRYPT = 1;
    const int DECRYPT = 2;

    if(selector == ENCRYPT){

        encrypt(key, stringArray);

        for(int i = 0; i < strlen(stringArray); i++){
            printf("%c", stringArray[i]);
        }
    }

    if(selector == DECRYPT){

        decrypt(key, stringArray);

        for(int i = 0; i < strlen(stringArray); i++){
            printf("%c", stringArray[i]);
        }
    }
}

int main(int argc, char** argv) {


    if (!strcmp(argv[1],"help") && argc == 2){
            printf("Name program [string] [key] [enencrypt-1 or decrypt-2]");
            return 1;
    }

    char *stringArray;
    int key ;
    int selector;

    stringArray = argv[1];
    key = (atoi(argv[2]));
    selector = (atoi(argv[3]));

    userChoice(selector, stringArray, key);

    return 0;
}



