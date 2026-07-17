#include <stdio.h>

double square(double x)
{
    return x * x;
}

int main(void)
{
    printf("4.0 ^ 2 is %.2f\n", square(4.0));
    return 0;
}
