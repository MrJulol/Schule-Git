#include <stdio.h>

int main(){
	
	int x1 = 0;
	int y1 = 0;
	
	int x2 = 0;
	int y2 = 0;
	
	int x3 = 0;
	int y3 = 0;
	
	int x4 = 0;
	int y4 = 0;
	
	int Entfernung1x = 0;
	int Entfernung1y = 0;
	int Entfernung2x = 0;
	int Entfernung2y = 0;
	int Entfernung3x = 0;
	int Entfernung3y = 0;
	
	int Entfernung = 0;
	
	printf("Enter the x-Coordinate of Point 1: \n");
	scanf("%d", &x1);
	printf("Enter the y-Coordinate of Point 1: \n");
	scanf("%d", &y1);
	printf("Enter the x-Coordinate of Point 2: \n");
	scanf("%d", &x2);
	printf("Enter the y-Coordinate of Point 2: \n");
	scanf("%d", &y2);
	printf("Enter the x-Coordinate of Point 3: \n");
	scanf("%d", &x3);
	printf("Enter the y-Coordinate of Point 3: \n");
	scanf("%d", &y3);
	printf("Enter the x-Coordinate of Point 4: \n");
	scanf("%d", &x4);
	printf("Enter the y-Coordinate of Point 4: \n");
	scanf("%d", &y4);
	
	Entfernung1x = x1 - x2;
	Entfernung1y = y1 - y2;
	Entfernung2x = x2 - x3;
	Entfernung2y = y2 - y3;
	Entfernung3x = x3 - x4;
	Entfernung3y = y3 - y4;
	
	if(Entfernung1x<=-1){
		Entfernung1x = -Entfernung1x;
	}
	if(Entfernung1y<=-1){
		Entfernung1y = -Entfernung1y;
	}
	if(Entfernung2x<=-1){
		Entfernung2x = -Entfernung2x;
	}
	if(Entfernung2y<=-1){
		Entfernung2y = -Entfernung2y;
	}
	if(Entfernung3x<=-1){
		Entfernung3x = -Entfernung3x;
	}
	if(Entfernung3y<=-1){
		Entfernung3y = -Entfernung3y;
	}
	
	Entfernung = (Entfernung1x + Entfernung1y) + ( Entfernung2x + Entfernung2y) + (Entfernung3x + Entfernung3y);
	
	printf("Die Entfernung beträgt: %d", Entfernung);
	
	
	return 0;
}