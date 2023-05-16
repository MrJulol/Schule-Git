#include <stdio.h>

int ggtf(int num1, int num2){
	
	int rest = 0;
	int ggt = 0;
	
	do{
		ggt = rest;
		rest = num1 % num2;
		num1 = num2;
		num2 = rest;
	}while(rest != 0);
		
	return ggt;
}

int main(){
	
	int num1 = 0;
	int num2 = 0;
	int temp = 0;
	int erg = 0;
	
	
	printf("Enter two numbers you want the biggest shared divider of: \n");
	scanf("%d", &num1);
	scanf("%d", &num2);
	
	
	if(num1<num2){
		temp = num2;
		num2 = num1;
		num1 = temp;
	}
	erg = ggtf(num1, num2);

	printf("\nThe biggest shared divider is: %d\n",erg);

	return 0;
}