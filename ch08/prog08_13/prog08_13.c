#include <stdio.h>

int fac(int n)
{
    int x = 2;
    int res = 1;

    while (x <= n)
    {
        res *= x;
        x++;
    }

    return res;
}

double my_fun(int n)
{
    int x = 1;
    double invSum = 0;

    while (x <= n)
    {
        invSum += 1.0 / fac(x);
        x++;
    }

    return invSum;
}

int main(void)
{
    // (a)
    printf("%f\n", my_fun(5));
    printf("%f\n", my_fun(8));
    printf("%f\n", my_fun(10));

    // (b)
    const double tol = 1e-5;
    int n = 2;
    while (1)
    {
        if (my_fun(n) - my_fun(n - 1) < tol)
        {
            printf("Threshold is %d\n", n);
            break;
        }
        n++;
    }
    return 0;
}
