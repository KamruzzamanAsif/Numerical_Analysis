#include<stdio.h>

int main(void){
    freopen("derivation.txt", "r", stdin);
    int n;
    scanf("%d", &n);

    double x0, x1, x2, f0, f1, f2;
    scanf("%lf%lf", &x0, &f0);
    scanf("%lf%lf", &x1, &f1);
    
    // first point (with forward difference)
    printf("%.2lf\n", (f1-f0)/(x1-x0));

    for(int i=3; i<=n; i++){
        scanf("%lf%lf", &x2, &f2);
        printf("%.2lf\n", (f2-f0)/(x2-x0));
        // swap
        x0 = x1;
        f0 = f1;
        x1 = x2;
        f1 = f2;
    }
    
    // last point (with backward difference)
    printf("%.2lf\n", (f1-f0)/(x1-x0));

    return 0;
}