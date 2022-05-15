#include <stdio.h>

int main(void){
    double x[] = {0.0, 0.2, 0.4, 0.6, 0.8};
    double fx[] = {0.0, 0.1, 0.3, 0.6, 1.0};

    double sum_odd = 0.0, sum_even = 0.0;

    double h = 0.2, area;
    
    for(int i=1; i<(sizeof(x)/sizeof(x[0]))-1; i++){
        if(i%2){
            sum_odd += fx[i];
        }
        else{
            sum_even += fx[i];
        }
    }

    area = fx[0] + fx[(sizeof(x)/sizeof(x[0]))-1] + (4*sum_odd) + (2*sum_even);

    area = (area*h)/3;

    printf("Area is: %.3lf\n", area);

    return 0;
}