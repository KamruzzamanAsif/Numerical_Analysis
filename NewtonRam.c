#include <stdio.h>
#include <math.h>
#define ep 10e-9

double function(double x){
    return (x*x*x)+(4*(x*x))-10;
}

// derivative function
double derf(double x){
    return (3*x*x)+(8*x);
}

double a = 1;
double b;


int main(void){



    int itr = 0;
    while(1){
        itr++;

        b = a - (function(a)/derf(a));

        double value = function(b);

        if( fabs(value) <= ep ){
            printf("Root is: %.6lf", b);
            printf("\nTotal itr = %d",itr);
            break;
        }
        a = b;
    }


    return 0;
}

