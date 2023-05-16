#include <stdio.h>


int main(){
	
	int num = 0;
	int hor = 0;
	int vert = 0;
	
	
	
	printf("Enter the number for the grid : ");
	scanf("%d", &num);
	
	for(vert = 1; vert<= num; vert++){
		if(vert = 1){
			for(hor = 1; hor <= num; hor++){
				printf("a\t");
				printf("\n");
			}
		}
		
		if(vert = num){
			for(hor = 1; hor <= num; hor++){
				printf("a\t");
				printf("\n");
			}
		}
		
		if(vert > 1 && vert < num){
			for(hor = 1; hor <= num; hor++){
				if(hor = 1){
					printf("a\t");
					printf("\n");
				}
				if(hor = num){
					printf("a\t");
					printf("\n");
				}
				else{
					printf("\t");
					printf("\n");
				}
			}
		}
		
		hor = 1;
		
	}
	
	
	
	
	return 0;
}