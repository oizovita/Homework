#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#define ADMIN_PINCODE 1618
#define NUMBER_0F_CELLS 5000
#define CHECK_BALANCE 1
#define REFILL 2
#define WITHDRAWAL 3
#define EXIT 0
#define ATTEMPTS 3

int main(void){

    srand(time(0));
    int userPincode;
    int actionToPerform;
    int operationsOnNamber;
    int paswordArray[NUMBER_0F_CELLS];
    int atmArray[NUMBER_0F_CELLS];
    int choiceOption;

    for(int k = 0; k < NUMBER_0F_CELLS; k++){
        atmArray[k] = rand() % 1000;

    }

    for(int j = 0; j < NUMBER_0F_CELLS; j++){
        paswordArray[j] = rand() % 8999+1000;
    }

    for (int i = 0; i < ATTEMPTS; i++){

        for(;;){
            printf("Enter pin-code:");
            int validation = scanf("%d",&userPincode);                                  //validation check

            if(validation){

            }
            else {
                printf("Your input is incorrect\n");

                scanf("%*[^\n]");

                continue;
            }
            break;
        }



            if(userPincode == ADMIN_PINCODE){                                                   //Check for admin picode

                for(int k = 0; k < NUMBER_0F_CELLS; k++){
                    printf(" %d \n",atmArray[k] );
                }

                printf("Do you want to clear all cells\n");
                printf("1/0\n");
                scanf("%d",&actionToPerform);

                if(actionToPerform == 1){

                    for(int k = 0; k < NUMBER_0F_CELLS; k++){
                        atmArray[k] = 0;
                        printf(" %d \n",atmArray[k] );
                    }


                    i = -1;

                    continue;
                }

                else{
                    i = -1;

                    continue;
                }
            }


        for ( int j = 0; j < NUMBER_0F_CELLS; j++){

            if(userPincode == paswordArray[j]){

                for(;;){                                                               //Optiont
                    printf("-----------------------------------------\n");
                    printf("|Choose what you want to do:            |\n");
                    printf("|If you want to see the balance, press 1|\n");
                    printf("|If you want to put money, press 2      |\n");
                    printf("|If you want to withdraw money , press 3|\n");
                    printf("|If you want to exit, press 0           |\n");
                    printf("-----------------------------------------\n");
                    printf("Enter option:");
                    scanf("%d",&choiceOption);

                    if(choiceOption > 3){
                        printf("You entered an invalid option\n");
                        printf("Re-enter\n");
                    }

                    if(choiceOption == CHECK_BALANCE){
                        printf("On your balance sheet %d\n", atmArray[j]);
                    }

                    if(choiceOption == REFILL){
                        printf("How much do you want to contribute?\n");
                        scanf("%d",&operationsOnNamber);
                        atmArray[j]=atmArray[j]+operationsOnNamber;
                    }

                    if(choiceOption == WITHDRAWAL){
                        printf("How much do you want to take\n");
                        scanf("%d",&operationsOnNamber);
                        if(operationsOnNamber <= atmArray[j]){
                            atmArray[j]=atmArray[j] - operationsOnNamber;
                        }
                        else{
                            printf("Not enough money\n");
                        }
                    }

                    if(choiceOption == EXIT){
                        return 0;
                    }
                }
            }

        }
    }
}






