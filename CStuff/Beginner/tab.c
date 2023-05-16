#include <stdio.h>

int main(){
	
	int num = 0;
	int vert = 0;
	int hor = 0;
	int mult = 1;
	
	printf("Enter a number (max 26)");
	scanf("%d", &num);
	
		for(vert = 1; vert <= num; vert++){
			for(hor = 1; hor <= num; hor++){
				printf("%d\t", hor * mult);
			}
			printf("\n");
			mult++;
		}
	return 0;
}