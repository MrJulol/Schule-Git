#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(){
    srand((unsigned)time(NULL));
    int counting[11] = {0};
    int g;
    printf("How many random numbers do you want? ");
    scanf("%d", &g);
    int ran[g];

    for (int i = 0; i<g;i++){
        ran[i] = (rand() % 10) +1;
    }
    /*for (int i = 0; i < g; i++){
        printf("Random Number %d: ", i+1);
        printf("%d \n", ran[i]);
    }*/
    for(int i = 0; i<g;i++){
        switch (ran[i]){
        case 0:
            counting[0] = counting[0]+1;
            break;
        case 1:
            counting[1] = counting[1]+1;
            break;
        case 2:
            counting[2] = counting[2]+1;
            break;
        case 3:
            counting[3] =  counting[3]+1;
            break;
        case 4:
            counting[4] = counting[4]+1;
            break;
        case 5:
            counting[5] = counting[5]+1;
            break;
        case 6:
            counting[6] = counting[6]+1;
            break;
        case 7:
            counting[7] = counting[7]+1;
            break;
        case 8:
            counting[8] = counting[8] +1;
            break;
        case 9:
            counting[9] = counting[9] +1;
            break;
        case 10:
            counting[10] = counting[10] +1;
        }
    }
        for(int i = 0; i<30;i++){
            printf("  %d\t", i);
        }
        printf("\n__________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________");
        int countprint = 0;
        for(int vert = 1; vert<=11;vert++){
            printf("%d\t|", countprint);
            for(int hor = 0; hor<counting[countprint];hor++){
                printf("[-]\t");
            }
            printf("\n");
            countprint++;

        }
    

        /*for(int i = 1; i<11;i++){
            printf("%ds: %d\n", i, counting[i]);
        }*/
    printf("\n");
    return 0;
    
}