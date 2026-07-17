#include <stdio.h>

int cub(int x)
{
    return x * x * x;
}

int main()
{
    printf("%d\n", cub(2)); // 8
    return 0;
}