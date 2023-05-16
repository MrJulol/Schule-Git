#include <stdio.h>
#include <stdlib.h>

//Faculty, Fibonacci and GGT

int fibonacci(int n) {
   if(n == 0){
      return 0;
   } else if(n == 1) {
      return 1;
   } else {
      return (fibonacci(n-1) + fibonacci(n-2));
   }
}


int main(){

    int fibo = 0;

    printf("Enter the number for the fibonacci series: ");
    scanf("%d", &fibo);

    for(int i = 0; i<fibo;i++){
        printf("%d", fibonacci(i));
    }printf("\n");
    return EXIT_SUCCESS;
}