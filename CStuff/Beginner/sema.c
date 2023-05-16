#include <stdio.h>

int main(){
	
	int x = 0;
	int y = 0;
	
	int x1 = 35;
	int y1 = 35;
	
	int x2 = 70;
	int y2 = 70;
	
	printf("Geben sie bitte die erste Koordinate zwischen (0,0) und (100,100) ein! \n");
	scanf("%d %d", &x, &y);
	
	if ((x > x1 && y > y1) && (x < x2 && y < y2)){
		printf("Ihre Koordinate liegt im Rechteck! \n");
	}
	else{
		printf("Ihre Koordinate liegt nicht im Rechteck! \n");
		
		if (x > x2){
			printf("Weiter links \n");
		}
		if (y < y1){
			printf("Weiter oben \n");
		}
		if (x < x1){
			printf("Weiter rechts \n");
		}
		if (y > y2){
			printf("Weiter unten \n");
		}
	}
	
	return 0;
}