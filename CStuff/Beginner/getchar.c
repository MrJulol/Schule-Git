#include <stdio.h>
#include <conio.h>


int main(){
	
	int num = 0;
	int numrs[100] = {0};
	int i = 0;
	int sum = 0;

	printf("Wie viele Zahlen wollen sie eingeben?");
	scanf("%d", &num);
	
	
		while((numrs[i] = _getch()) != 27){
			i++;
		}

	for(int u = 0; u <= num; u++){
		sum = sum + numrs[u];
	}
	return 0;
}