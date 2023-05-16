#include <stdio.h>

int main(){
	
	int x = 0;
	int y = 0;
	int erg = 1;
	
	printf("Enter the base then the power: \n");
	scanf("%d", &x);
	scanf("%d", &y);
	
	printf("\n%d to the power of %d = ", x,y);
	for(int i = 0; i < y; i++){
		erg = erg * x;
	}
	printf("%d", erg);
	
	
	
	
	return 0;
}