#include <stdio.h>  
#include <math.h>

int main(){

	const double PI = 3.1415;
	double rad = 0;
	double a = 0;

	printf("Gib den Radius des Kreises an: ");
	scanf("%lf", &rad);
	
	a = pow(rad, 2);
	a = a * PI;

	printf("%.3lf", a);	

	return 0;
}