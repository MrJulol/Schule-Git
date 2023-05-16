#include <stdio.h>
int main(){
	
	int size = 0;
	int a[] = {0};
	int c = 0;
	
while(a[size] != 'e'){	
	a[size] = getchar();
	a[size] = a[size] -48;
	size = size +1;
}
	printf("%d", a[0]);
	
	
	
return 0;	
}