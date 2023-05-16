#include <stdio.h>

int eingabe(){
	int num = 0; 
	do{
		printf("Limit: ");
		scanf("%d", &num);
	}while (num<1);
	return num;
}

void finish(int num){
	for (int prim = 2; prim <= num; prim++){
		if (prim == 2 || prim == 3 || prim == 5 || prim == 7){
			continue;
		}
		else if (prim % 2 == 0 || prim % 3 == 0 || prim % 5 == 0 || prim % 7 == 0){ 
			printf("%d ist eine Primzahl\n", prim);
			continue;
		}	
	}
}

int main(){
	int num = eingabe();
	
	finish(num);
	
	return 0;
}

