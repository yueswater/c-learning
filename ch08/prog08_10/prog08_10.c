#include <stdio.h>

int power(int x, int n)
{
    int res = 1;
    int count = 0;

    while (count < n)
    {
        res *= x;
        count++;
    }
    return res;
}

int isMersenne(int x)
{
    int n = 0;
    while (n <= x)
    {
        if (x == power(2, n) - 1)
            return 1;
        n++;
    }
    return 0;
}

int main(void)
{
    // Check 7 & 8
    printf("%d\n", isMersenne(7)); // 1
    printf("%d\n", isMersenne(8)); // 0

    // Find first 8 Mersenne primes
    int count = 0;
    int currNum = 1;

    printf("First 8 Mersenne primes are: ");
    while (count < 8)
    {
        if (isMersenne(currNum))
        {
            if (count != 7)
                printf("%d, ", currNum);
            else
                printf("%d", currNum);
            count++;
        }
        currNum++;
    }
    printf("\n");
    return 0;
}
