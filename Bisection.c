#include <stdio.h>
#include <math.h>
#define ep 10e-9

double function(double x){
    return (x*x*x)+(4*(x*x))-10;
}

double a = 1;
double b=2;
double c;

int main(void){
    if(function(a)*function(b)>0){
        printf("No root");
        return -1;
    }

    int itr = 0;
    while(1){
        itr++;

        c = (a+b)/2;

        double value = function(c);
        if( fabs(value) <= ep ){
            break;
        }
        // next itr
        if(function(a)*function(c) < 0.0)
            b = c;
        else
            a = c;
    }

    printf("Root is: %.6lf", c);
    printf("\nTotal itr = %d",itr);

    return 0;
}
