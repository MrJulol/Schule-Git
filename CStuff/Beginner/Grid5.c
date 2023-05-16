#include <stdio.h>

int main(){

    int num = 0;
	int vert = 0;
	int hor = 0;
    int counter = 1;
    
	
	printf("Enter a number (max 24)");
	scanf("%d", &num);
		for(vert = 1; vert <= num; vert++){
            for(hor = 1; hor <= counter; hor++){
                printf("a\t");
            }
            printf("\n");
            hor = 1;
            counter++;
            
		}
		
    return 0;
}