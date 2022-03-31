#include <stdio.h>
#include <math.h>

#define f1(y,z)  (85-(3*y)+(2*z))/15
#define f2(x,z)  (51-(2*x)-z)/10
#define f3(x,y)  (5-x+(2*y))/8

#define ep 1e-9

int main(void){
    double x_old, y_old, z_old, x_new, y_new, z_new, e1, e2, e3, max_error;
    x_old = y_old = z_old = 0.0;
    int itr=0;

    while(1){
        itr++;

        //Jaccob
        // x_new = f1(y_old,z_old);
        // y_new = f2(x_new,z_old);
        // z_new = f3(x_new,y_new);

        //Gaus
        x_new = f1(y_old,z_old);
        y_new = f2(x_new,z_old);
        z_new = f3(x_new,y_new);

        e1 = fabs(x_old-x_new);
        e2 = fabs(y_old-y_new);
        e3 = fabs(z_old-z_new);

        if(e1>e2 && e2>e1){
            max_error = e1;
        }
        else if(e2>e1 && e1>e3){
            max_error = e2;
        }
        else{
            max_error = e3;
        }

        x_old = x_new;
        y_old = y_new;
        z_old = z_new;

        if(max_error<ep)
            break;
    }

    printf("Total iteration: %d\n", itr);
    printf("Answer: x=%0.3lf, y=%0.3lf and z = %0.3lf\n",x_new,y_new,z_new);

    return 0;
}