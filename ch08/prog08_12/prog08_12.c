#include <stdio.h>

int power(int x, int n)
{
    int count = 0;
    int res = 1;
    while (count < n)
    {
        res *= x;
        count++;
    }
    return res;
}

double my_fun(int n)
{
    int i = 1;
    double invSum = 0;
    while (i <= n)
    {
        invSum += 1.0 / (power(2, i));
        i++;
    }
    return invSum;
}

int main(void)
{
    // (a)
    printf("%f\n", my_fun(3));
    printf("%f\n", my_fun(4));
    printf("%f\n", my_fun(5));
    printf("%f\n", my_fun(6));

    // (b)
    for (int n = 1; n <= 20; n++)
    {
        printf("Sum from 1 to %d is %f\n", n, my_fun(n));
    }

    // (c)
    int n = 1;
    while (1)
    {
        if (my_fun(n) > 0.99999)
        {
            printf("After n = %d, my_fun(n) > 0.99999\n", n);
            break;
        }
        else
        {
            n++;
        }
    }
    return 0;
}
