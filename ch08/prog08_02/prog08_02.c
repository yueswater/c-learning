#include <stdio.h>

void kitty(int k)
{
    for (int i = 0; i < k; i++)
    {
        printf("Hello Kitty\n");
    }
}

int main()
{
    kitty(10);
    return 0;
}