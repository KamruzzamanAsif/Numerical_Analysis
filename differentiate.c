#include<stdio.h>
#include<math.h>

double func(double x){
    return (x*x*x)+(4*x*x)-10;
}

double dfunc(double x){
    return (3*x*x)+(8*x);
}

#define n 300
double x[n+1];
double f[n+1];
double df[n+1];
double ff[n+1];  // for defined derivative function 
double h = (10.0-0.0)/300.0;  // bound was 0 to 300

int main(void){
    // input
    x[0] = 0.0;
    f[0] = func(0);
    ff[0] = dfunc(0);
    for(int i=1; i<n; i++){
        x[i] = x[i-1] + h;
        f[i] = func(x[i]);
        ff[i] = dfunc(x[i]);
    }
    x[n] = 10.0;
    f[n] = func(10.0);
    ff[n] = dfunc(10.0);


    // 2nd part calculate differentiation
    df[0] = (f[1]-f[0])/h;

    for(int i=1; i<n; i++){
        df[i] = (f[i+1]-f[i-1])/(2*h);
    }

    df[n] = (f[n]-f[n-1])/h;
    

    // find max difference and print
    double  temp = 0.0;
    for(int i=0; i<=n; i++){
        if(fabs(ff[i]-df[i])>temp)
            temp = fabs(ff[i]-df[i]);
    }
    printf("%lf\n", temp);

    return 0;
}