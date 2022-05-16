#include<stdio.h>
#include<math.h>

double func(double x){
    return x*sin(x);
}

#define n 100

int main(void){
    double x[n+1];
    double f[n+1];
    double df[n+1];

    double a = -3, b = 3;
    double h = (b-a)/n;

    x[0] = a;
    f[0] = func(a);
    for(int i=1; i<n; i++){
        x[i] = x[i-1] + h;
        f[i] = func(x[i]);
    }
    x[n] = b;
    f[n] = func(b);

    // 2nd part calculate differentiation
    df[0] = (f[1]-f[0])/h;
    for(int i=1; i<n; i++){
        df[i] = (f[i+1]-f[i-1])/(2*h);
    }
    df[n] = (f[n]-f[n-1])/h;
    
    // print ans
    printf("Answer:");
    for(int i=0; i<n+1; i++){
        printf("\nx = %.3lf\tf(x) = %.3lf\tdf(x) = %.3lf", x[i], f[i], df[i]);
    }
    
    return 0;
}