#include <stdio.h>
#include <conio.h>

int main ()
{
    int ch = 0;

    while ((ch = _getch()) != 27){
		switch(ch){
			case 32 :
				printf("Space");
				break;
			case 13:
				printf("Enter");
				break;
			default:
			printf("%c", ch);
       }
        if (ch == 0 || ch == 224){
			switch (_getch ()){
				case 77: 
					printf("\rArrow right");
					break;
				case 80:
					printf("\rArrow down");
					break;
				case 72:
					printf("\rArrow up");
					break;
				case 75:
					printf("\rArrow left");
					break;
			}
		}
	printf("\n");
    }
    printf("ESC");

    return (0);
}