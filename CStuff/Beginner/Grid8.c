#include <stdio.h>

int main(){

    int num = 0;
	int vert = 0;
	int hor = 0;
	
	printf("Enter a number (max 24)");
	scanf("%d", &num);
	
		for(vert = 1; vert <= num; vert++){
			if(vert%2 == 1){
				for(hor = 1; hor <= num; hor++){
					if(hor%2 == 1){
						printf("a\t");
					}
					if(hor%2 == 0){
						printf("-\t");
					}
				}
			}
			else{
				for(hor = 1; hor <= num; hor++){6
					if(hor%2 == 0){
						printf("a\t");
					}
					if(hor%2 == 1){
						printf("-\t");
					}
				}
			}
			printf("\n");
			hor = 1;
		}
		
    return 0;
}