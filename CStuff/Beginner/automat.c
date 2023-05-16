#include <stdio.h>

int main(){
	
	float money = 0;
	const float BEV1 = 0.5;
	const float BEV2 = 1.0;
	const float BEV3 = 2.0;
	int order = 0;

	printf("Werfen sie bitte ihr Geld ein: Format: Euro.cent \n");
	scanf("%f", &money);
	
	printf("Wählen sie ihr Getränk aus: 1 = BEV1, 2 = BEV2, 3 = BEV3 \n");
	scanf("%d", &order);
	
	switch(order){
		case 1:
			money = money - BEV1;
			if(money < 0){
				printf("Error, zu wenig Geld: %.2f", money);
			}
			else{
				printf("Sie haben BEV1 gekauft. Rest: %.2f \n", money);
			}
			break;
		case 2:
			money = money - BEV2;
			if(money < 0){
				printf("Error, zu wenig Geld: %d", money);
			}
			else{
				printf("Sie haben BEV2 gekauft. Rest: %.2f \n", money);
			}
			break;
		case 3:
			money = money - BEV3;
			if(money < 0){
				printf("Error, zu wenig Geld: %d", money);
			}
			else{
				printf("Sie haben BEV3 gekauft. Rest: %.lf \n", money);
			}
			break;
		default:
			printf("ERROR");
	}
	
	return 0;
}
