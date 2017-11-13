#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#define ATTEMPTS 3
int main(void)
{
    int random,myNumber;
    char exit;


    for(;;){
       srand(time(0));
       random =  rand() % 10;

       for (int i = 0; i < ATTEMPTS; i++){

           for(;;){
              printf("enter numder:");
              int validation = scanf("%d",&myNumber);               //validation check

              if(validation){

              }
              else {
                printf("Your input is incorrect\n");
                scanf("%*[^\n]");

                 continue;
              }

              if (myNumber<0){
                 printf("negativ\n");
                 continue;
              }
                 break;
          }
                                                  //comparison of numbers

              if (myNumber<random){
                 printf("bigger\n");
              }

              if(myNumber>random){
                 printf("Smaller!\n");
              }
              if(myNumber==random){
                printf("good\n");
                return 0;
              }


      }
      printf("entre y/n\n");
      scanf("%s",&exit);

      if(exit=='n'){
        return 0;
      }
      else
        continue;
  }
}







