#include <stdio.h>

int ggT(int a, int b) {
    if (b == 0) return a;
    return ggT(b, a % b);
}

int main() {
    int a,b;

    printf("Enter two numbers you want the biggest shared divisor of: \n");
    scanf("%d", &a);
    scanf("%d", &b);
    

    int c = ggT(a, b);
    printf("The biggest shared divisor is: %d\n", c);
    return 0;
}

