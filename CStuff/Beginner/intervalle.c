#include <stdio.h>


int eins(){
	
	int a = 0;
	scanf("%d", &a);
	if(a>=4 && a<=6){
		printf("Okeeeeee");
		return 0;
	}
	else{
		printf("no okeeeee");
		return 0;
	}
}
int zwei(){
	
	int b = 0;
	scanf("%d", &b);
	if(b>=0 && b<=2 || b>=4 && b<=10){
		printf("Okeeeeee");
		return 0;
	}
	else{
		printf("no okeeeee");
		return 0;
	}
}

int drei(){
	
	int c = 0;
	scanf("%d", &c);
	if(c <= -1 || c >= 1){
		printf("Okeeeeee");
		return 0;
	}
	else{
		printf("no okeeeee");
		return 0;
	}
}

int vier(){
	
	int d = 0;
	scanf("%d", &d);
	if(d <= -4 || d >= 4 || d>=0 && d<= 2){
		printf("Okeeeeee");
		return 0;
	}
	else{
		printf("no okeeeee");
		return 0;
	}
}

int main(){
	
	int choose = 0;
	printf("Numbers 1-4 to choose: ");
	scanf("%d", &choose);
	
	if(choose == 1){
		eins();
	}
	else if(choose == 2){
		zwei();
	}
	else if(choose == 3){
		drei();
	}
	else if(choose == 4){
		vier();
	}
}

