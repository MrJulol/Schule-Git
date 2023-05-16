#include <stdio.h>
#include <stdlib.h>

//Faculty, Fibonacci and GGT

unsigned long long calcfaculty(int num){
    if(num>=1){
        return num*calcfaculty(num-1);
    }
    else return 1;
}

int main(){

    int num = 0;


    printf("Enter the number you want the factorial of: ");
    scanf("%d", &num);

    printf("Factorial of %d is: %llu", num, calcfaculty(num));




    printf("\n");
    return EXIT_SUCCESS;
}