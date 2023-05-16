#include <stdio.h>
int main(){
	
	
	
	int val = 1;
	printf("1. val : %d\n", val);	//1
	val++;//++
	printf("2. val : %d\n", val);//2
	printf("3. val : %d\n", val++);//2 val ++
	printf("4. val : %d\n", val);//3
	printf("5. val : %d\n", ++val);//val++ 4
	printf("6. val : %d\n", val);//4
	printf("7. val : %d\n", (val + --val)); //val-- 3+3 = 6
	printf("8. val : %d\n", val);//3
	int abc = val + val++;//3+4 val++
	printf(">> abc : %d\n", abc);//7
	printf("9. val : %d\n", val++);//4
	printf("10. val : %d\n", val);
	
	
return 0;
}