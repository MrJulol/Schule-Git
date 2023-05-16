#include <stdio.h>
#include <stdlib.h>

int main(){
    int arraylocation = 6;
    int arraylocation2 = 0;
    int arraylocation3 = 0;
    int A[] = {2, 34, 5, 6, 3, 17};
    int B[] = {2, 4, 3, 46, 39, 17};
    int C[9] = {0};
    int A2[] = {2, 34, 5, 6, 3, 17};
    int B2[] = {2, 4, 3, 46, 39, 17};
    int C2[3] = {0};
    int A3[] = {2, 34, 5, 6, 3, 17};
    int B3[] = {2, 4, 3, 46, 39, 17};
    int C3[3] = {0};

    for(int i = 0; i<6;i++){
        C[i] = A[i];
    }

    for(int i = 0; i<6;i++){
        if(C[0] != B[i]&&C[1] != B[i]&&C[2] != B[i]&&C[3] != B[i]&&C[4] != B[i]&&C[5]){
            C[arraylocation] = B[i];
            arraylocation++;
        }
    }

    for(int i =0; i<6;i++){
        if(B2[0] == A2[i] || B2[1] == A2[i] || B2[2] == A2[i] || B2[3] == A2[i] || B2[4] == A2[i] || B2[5] == A2[i]){
            C2[arraylocation2] = A2[i];
            arraylocation2++;
        }
    }

    for(int i =0; i<6;i++){
        if(!(B3[0] == A3[i] || B3[1] == A3[i] || B3[2] == A3[i] || B3[3] == A3[i] || B3[4] == A3[i] || B3[5] == A3[i])){
            C3[arraylocation3] = A3[i];
            arraylocation3++;
        }
    }




    printf("AuB = {");
    for(int i = 0; i<9;i++){
        printf("%d, ", C[i]);
    }
    printf("\b\b} \n");
    
    printf("A^B = {");
    for(int i = 0; i<3;i++){
        printf("%d, ", C2[i]);
    }
    printf("\b\b} \n");

    printf("A/B = {");
    for(int i = 0; i<3;i++){
        printf("%d, ", C3[i]);
    }
    printf("\b\b} \n");

    return EXIT_SUCCESS;
}

