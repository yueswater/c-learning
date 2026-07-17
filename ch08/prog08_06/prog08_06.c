#include <stdio.h>

int power(int x, int n)
{
    int result = 1;
    int count = 0;
    while (count < n)
    {
        result *= x;
        count++;
    }

    return result;
}

int main(void)
{
    printf("%d\n", power(5, 3)); // 125
    return 0;
}
