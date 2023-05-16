#include <stdio.h>
#include <stdlib.h>

int main(){

    int Array1[10] = {0};
    int Array2[10] = {0};

    printf("Enter the numbers of the 1st Array: ");

    for(int i = 0; i<10;i++){
        scanf("%d", &Array1[i]);
    }

    printf("Enter the numbers of the 2nd Array: ");
    for(int i = 0; i<10;i++){
        scanf("%d", &Array2[i]);
    }
  
    for(int i = 0; i<10;i++){
        if(Array1[i] != Array2[i]){
            printf("The Arrays dont contain the same numbers");
            break;
        }
        if(i==9){
            printf("The Arrays contain the same numbers");
        }
    }
    
    printf("\n");
    return EXIT_SUCCESS;
}