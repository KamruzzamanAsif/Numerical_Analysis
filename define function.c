#include <stdio.h>

#define funct(x) ((x)*(x))

//double funct(double x){
//    return x*x;
//}

int main(){
    printf("%lf %lf", 1.0+1.0, funct(1.0+1.0));

    return 0;
}
