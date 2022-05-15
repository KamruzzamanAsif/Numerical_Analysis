#include <stdio.h>

#define f(x) ((x*x)+1)
#define n 200

int main(void){
    double a = 0, b = 1, h, area;

    h = (b-a)/n;

    area = (f(a) + f(b))* 0.5;
    
    for(int i=1; i<n; i++){
        a += h;
        area += f(a); 
    }

    area = area*h;

    printf("Area is: %.3lf\n", area);

    return 0;
}