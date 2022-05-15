#include <stdio.h>
#include <math.h>
#define ep 1e-9

#define f(x) sqrt(x)
#define g(x) x*x
#define h(x) f(x)-g(x)

double bisection(double a, double b){
    double c;

    if(h(a)*h(b)>0){
        printf("No root");
        return -1;
    }

    while(1){
        c = (a+b)/2;

        if( fabs(h(c)) <= ep ){
            break;
        }
        
        if(h(a)*h(c) < 0.0)
            b = c;
        else
            a = c;
    }

    return c;
}

double simpson(double a, double b, int n){
    double h = (b-a)/n;
    double area, fx[n+1];
    double sum_odd = 0.0, sum_even = 0.0;

    int i=0;
    double x = a;
    while(x<=b){
        fx[i++] = h(x);
        x += h;
    }
    
    for(int i=1; i<(sizeof(fx)/sizeof(fx[0]))-1; i++){
        if(i%2){
            sum_odd += fx[i];
        }
        else{
            sum_even += fx[i];
        }
    }
    area = fx[0] + fx[(sizeof(fx)/sizeof(fx[0]))-1] + (4*sum_odd) + (2*sum_even);
    area = (area*h)/3;

    return area;
}

int main(void){
    
    int n;
    printf("Input interval: ");
    scanf("%d", &n);

    if(n%2 != 0){
        printf("\nSimpson Method can't be applied. Interval must be even");
        return 0;
    }

    double a, area;

    a = bisection(1.0, 2.5); // parameter value is given in question

    area = simpson(0.0, a, n);

    printf("Area is: %.3lf\n", area);

    return 0;
}