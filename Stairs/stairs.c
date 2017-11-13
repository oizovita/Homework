#include <stdio.h>

int main(){
    int floor;
    int i;
    printf("Enter number of floors:");
    scanf("%d",&floor);


    for(i = 0;i <= floor; i++){             // build a pyramid from min to max

        for(int a = 0; a < i; a++){
             printf("*");
        }
       printf("\n");
    }
    printf("\n");

    for(i = 0; i <= floor; i++){            //build a pyramid from max to min

        for(int a = floor; a > i ;a--){
            printf("*");
        }
        printf("\n");
    }

    for(i = 1;i <= floor; i++){             //building tree

        for( int k = 1; k <= floor-i; k++){
            printf(" ");
        }

        for(int j = 1;j <= i*2-1;j++){
            printf("*");
        }
        printf("\n");

    }

    for(i = 1; i <= floor-1; i++){          //stump
         printf(" ");
     }

    printf("*");
    printf("\n");
    return (0);
}
