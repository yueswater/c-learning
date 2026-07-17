#include <stdio.h>

double power(double x, int n)
{
    double result = 1.0;
    int count = 0;
    while (count < n)
    {
        result *= x;
        count++;
    }

    return result;
}

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

double my_fun(double x, int n)
{
    int k = 1;
    double invSum = 0;

    while (k <= n)
    {
        invSum += power(x, k) / fac(k);
        k++;
    }

    return invSum;
}

int main(void)
{
    // (a)
    printf("%f\n", my_fun(0.1, 5));
    printf("%f\n", my_fun(0.1, 8));
    printf("%f\n", my_fun(0.2, 8));

    // (b)
    const double tol = 1e-5;
    int n = 2;
    while (1)
    {
        if (my_fun(0.1, n) - my_fun(0.1, n - 1) < tol)
        {
            printf("Threshold is %d\n", n);
            break;
        }
        n++;
    }
    return 0;
}
