#include <stdio.h>

int main(){
	
	int a = 0;
	int b = 0;
	int erg = 1;
	
	printf("Enter a number");
	scanf("%d", &a);
	b = a;
	printf("!%d = ", a);
	for(int i = 0; i < b; i++){
		printf("%d*", a);
		erg = erg * a;
		a--;
		if(a == 0){
			printf("\b ");
		}
	}
	printf("= %d", erg);
	
	return 0;
}