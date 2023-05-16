#include <stdio.h>
#include <math.h>

int main(){
	
	double a = 0.0;
	double b = 0.0;
	double c = 0.0;
	double x1 = 0.0;
	double x2 = 0.0;
	
	double ac4 = 0.0;
	double bsquared = 0.0;
	double root = 0.0;
	double bneg = 0.0;
	double a2 = 0.0;
	double discriminant = 0.0;
	
	
	printf("This is a Programm to solve a quadratic Equation\n");
	printf("Enter the numbers in the following oreder: \n");
	printf("axsqared, bx, c \n");
	printf("Hit enter after every number\n\n");
	
	printf("Number one: a (x- squared): ");
	scanf("%lf", &a);
	printf("\nNumber two: b (x): ");
	scanf("%lf", &b);
	printf("\nNumber three: c: ");
	scanf("%lf", &c);
	
	ac4 = 4 * (a * c);
	bsquared = pow(b,2);
	discriminant = bsquared - ac4;
	root = sqrt(discriminant);
	bneg = -b;
	a2 = 2 * a;
	
	x1 = (bneg + root)/a2;
	x2 = (bneg - root)/a2;
	
	if(discriminant > 0){
		printf("x1 = %lf\n", x1);
		printf("x2 = %lf\n", x2);
	}
	else if(discriminant == 0){
		printf("x1 = %lf\n", x1);
	}
	else if(discriminant < 0){
		printf("This equation has no result except one with\nimaginary numbers, and i dont want to code those xD\n");
		printf("Example for an imaginary Number: i (The Squareroot of -1)");
	}
	return 0;
}