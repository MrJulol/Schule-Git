#include <stdio.h>  

double flaeche();
double umfang();
void printab();

int main(){
	
	double lange = 0;
	double breite = 0; 
	double a = 0;
	double u = 0;
	
	do {
		printf("Gib die Laenge des Rechtecks in cm ein:\n ");
		scanf("%lf", &lange);
	}while(lange < 0);
		
	do{
		printf("Gib die Breite des Rechtecks in cm ein: \n");
		scanf("%lf", &breite);
	}while(breite < 0);
	
	a = flaeche(lange, breite);
	u = umfang(lange, breite);

	printab(a,u);
	
	return 0;
}

double flaeche(double a , double b){

	return a*b;
}

double umfang(double a, double b){

	double temp = (2*a)+(2*b);
	return temp;
}

void printab(double area, double other){

	printf("Die Fläche betraegt: %.2lfcm\n", area);
	printf("Der Umfang betraegt: %.2lfcm\n", other);
}