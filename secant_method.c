#include <stdio.h>
#include <math.h>
#define ep 10e-9

#define f(x) ((x*x*x)+(4*x*x)-10)

//double f(double x){
 //   return (x*x*x)+(4*(x*x))-10;
//}

double a=1;
double b=2;
double c;

int main(){
    if(f(a)*f(b)>0){
        printf("No root");
        return -1;
    }

    int itr = 0;
    while(1){
        itr++;

        c = ((a*f(b))-(b*f(a))) / (f(b)-f(a));
        double value = f(c);
        if( fabs(value) <= ep ){
            printf("Root is: %.6lf", c);
            printf("\nTotal itr = %d",itr);
            break;
        }
        a = b;
        b = c;
    }

    return 0;
}
