#include <stdio.h>

int getnum(){
    int num;
    do{
        printf("Enter the number you want to convert: ");
        scanf("%d", &num);
    }while(num<=0);

    return num;
}

void binary(int num){
    int bin[8] = {0};
    for(int i = 0; i < 7; i++){
        bin[i] = num % 2;
        num = num / 2;
    }
    for(int x = 7; x >= 0; x--){
        printf("%d", bin[x]);
    }
    printf("\n");
}

void hexadecimal(int num){
    int hex[2] = {0};
    for(int i = 0; i<1;i++){
        hex[i] = num % 16;
        num = num / 16;
    }
    if(hex[1] == 10){
        printf("A");
    }
    else if(hex[1] == 11){
        printf("B");
    }
    else if(hex[1] == 12){
        printf("C");
    }
    else if(hex[1] == 13){
        printf("D");
    }
    else if(hex[1] == 14){
        printf("E");
    }
    else if(hex[1] == 15){
        printf("F");
    }
    else if(hex[1] == 0){

    }
    else{
        printf("%d", hex[1]);
    }

  if(hex[0] == 10){
        printf("A");
    }
    else if(hex[0] == 11){
        printf("B");
    }
    else if(hex[0] == 12){
        printf("C");
    }
    else if(hex[0] == 13){
        printf("D");
    }
    else if(hex[0] == 14){
        printf("E");
    }
    else if(hex[0] == 15){
        printf("F");
    }
    else{
        printf("%d", hex[0]);
    }
    printf("\n");
    
}

int main(){

    int num = getnum();
    binary(num);        //calculate and priint binary
    hexadecimal(num);   //calculate and print hexanum

    return 0;
}