#include <stdio.h>

#define f(x) ((x*x)+1)
#define n 200

int main(void){
    double a = 0, b = 1, h, area;
    double odd_sum = 0.0, even_sum = 0.0;

    h = (b-a)/n;

    area = f(a) + f(b);
    
    for(int i=1; i<n; i++){
        a += h;

        if(i%2 == 0){
            even_sum += f(a);
        }
        else{
            odd_sum += f(a);
        }
    }

    area += (4*odd_sum + 2*even_sum);
    area = area * (h/3);    

    printf("Area is: %.3lf\n", area);

    return 0;
}