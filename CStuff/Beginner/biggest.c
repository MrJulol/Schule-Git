#include <stdio.h>

int main(){
	
	int num = 0;
	int numrs[1000] = {0};
	int biggest = 0;
	
	
	printf("Wie viele Zahlen wollen sie eingeben?\n");
	scanf("%d", &num);
	
	for(int i = 1; i <= num; i++){
		printf("Zahl %d: ", i);
		scanf("%d", &numrs[i]);
	}
	for(int u = 1; u <= num; u++){
		if(numrs[u] >= biggest){
			biggest = numrs[u];
		}	
	}
	
	printf("The biggest number is: %d\n", biggest);
	
	return 0;
	
}
