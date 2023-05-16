#include <stdio.h>

int main(){
	
	int a = 0;
	int b = 0;
	
	printf("Enter two numbers you want the sum of: \n");
	scanf("%d", &a);
	scanf("%d", &b);
	
	printf("%d + %d = \n", a,b);
	for(int i = 0; i < b; i++){
		printf("%d + 1 = ", a);
		a+=1;
		printf("%d \n",a);	
	}
	
	return 0;
}