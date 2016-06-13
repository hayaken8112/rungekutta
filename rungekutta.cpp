#include <iostream>
#include <math.h>
#define IMAX 100001
double func(double x, double y)
{
    double dydx;
    dydx = cos(x);
    
    return (dydx);
            
}

double rungeKutta(double x[], double y[], double final_x, int n, double (*func)(double, double))
{
    double h, f1, f2, f3, f4;

    h = (final_x - x[0]) / n;

    for (int i = 0; i < n; i++){
        f1 = h * func(x[i], y[i]);
        f2 = h * func(x[i] + h/2, y[i] + f1/2);
        f3 = h * func(x[i] + h/2, y[i] + f2/2);
        f4 = h * func(x[i] + h, y[i] + f3);
        y[i+1] = y[i] + (f1 + 2 * f2 + 2 * f3 + f4)/6;
        x[i+1] = x[i] + h;
        std::cout << x[i] << " " << y[i] << std::endl;
    }
    return y[n-1];
    
}

int main()
{
    double x[IMAX], y[IMAX];
    double final_x;
    int n;

    x[0] = 0.0;
    y[0] = 0.0;

    final_x = 100.0;
    n = 10000;

    rungeKutta(x, y, final_x, n, func);
    

    
    return 0;
    
}

