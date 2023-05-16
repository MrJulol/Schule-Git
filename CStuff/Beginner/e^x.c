#include <stdio.h>
#include <math.h>

int faculty();

int main(){

    double x = 0.0f;
    double fac = 0.0f;
    int n = 15;
    double result = 0.0f;
    double partresult = 0.0f;

    printf("\ne to the power of: ");
    scanf("%lf", &x);
    printf("\n\ne^%lf = ", x);

    /*for(;;){    //Reduces n if its bigger then 2^30
    
       if (pow(x,n) > pow(2,30)-1){
            n--;
            continue;
       }
        else{
            break;
        }
    }           
    */
    result = 1+x; //!0 + !1
    for(int i = 2; i<=n;i++){
        fac = faculty(i);  
        partresult = (double)pow(x,i) / fac; //fixing error 
        result = result + partresult;
    }
    printf("%lf", result); 

    float exp_func = exp((float)x); //exp_function of math.h   e^x
    printf("\n\nResult using exp function: %.6lf \n", exp_func);
    //printf("\nn = %d\n", n); //TEST for n Reduction
    return 0; 
}


int faculty(int num){
    int faculty = 1;
    for(int i = 1; i<=num;++i){
        faculty *= i;
    }
    return faculty;
} 