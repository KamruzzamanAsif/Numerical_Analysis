#include <stdio.h>

#define f(x) ((x*x)+1)
#define n 200

int main(void){
    double a = 0, b = 1, h, area;

    h = (b-a)/n;

    area = f(a) + f(b);
    
    for(int i=1; i<n; i++){
        a += h;

        if(i%2 == 0){
            area += (2*f(a)); 
        }
        else{
            area += (4*f(a)); 
        }
    }

    area = (area*h)/3;

    printf("Area is: %.3lf\n", area);

    return 0;
}