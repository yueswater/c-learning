#include <stdio.h>

int mod(int x, int y)
{
    return x % y;
}

int main(void)
{
    int x = 17;
    int y = 5;
    printf("%d mod %d is %d\n", x, y, mod(x, y)); // 2
    return 0;
}
