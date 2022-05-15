#include <stdio.h>
#include <math.h>

#define ep 1e-3

#define f(x) ((x*x*x)-(2*x)-3)
#define Q(x) cbrt((2*x)+3)

int main(void){
    double a, b;
    printf("Input an interval: ");
    scanf("%lf%lf", &a, &b);

    if(f(a)*f(b) > 0){
        printf("Root doesn't lies in this interval.");
        return 0;
    }

    double x0 = a; //initial approximation
    double xn;

    while(1){
        xn = Q(x0);
        if(fabs(xn-x0) < ep){
            printf("Root is: %.3lf", xn);
            break;
        }
        x0 = xn;
    }

    return 0; 
}