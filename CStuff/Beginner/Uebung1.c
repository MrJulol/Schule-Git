#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int maximum();

int main(){
	
	int g = 0;
	int anzahl[10] = {0};
	int max1 = 0;
	int max2 = 0;
	
	printf("Wie viele Zufallszahlen haetten Sie gerne\n");
	scanf("%d", &g);
	
	int ZZ[g];
	
	srand(time(NULL));
	
	for(int i = 0; i < g; i++){
		
		ZZ[i] = rand()%10+1;
		
		for(int j = 0; j < 10; j++){
			if (ZZ[i] == j+1){
				anzahl[j]++;
			}
		}
	}
	
	for(int i = 0; i < 10; i++){
	printf("%d  = %d\n",i + 1, anzahl[i]);
	}
	
	printf("\n\n\n");
	
	max1 = maximum(anzahl, max1);
	max2 = max1;
	
	for(int i = 0; i < max1; i++){
		
		printf("%d\t|\t", max2);
		
		for(int j = 0; j < 10; j++){
			
			if (anzahl[j] == max2){			
				printf("o\t");
				anzahl[j]--;
			}else{			
				printf("\t");
				}
			
		}
			printf("\n");
			max2--;
		
	}
	
	printf("____________________________________________________________________________________________\n");
	printf("\t\t1\t2\t3\t4\t5\t6\t7\t8\t9\t10");	
	
	return 0;
}

int maximum(int anzahl[], int max){
	
	max = anzahl[0];
	
	for(int i = 1; i < 10;i++){
		
		if (max < anzahl[i]){
			
			max = anzahl[i];
			
		}
		
	}
	return max;
}