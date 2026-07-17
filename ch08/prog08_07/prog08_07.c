#include <stdio.h>

int prime(int n)
{
    if (n == 1)
        return 2;

    int count = 1;
    int num = 3;

    while (count < n)
    {
        int is_prime = 1;
        for (int i = 3; i * i <= num; i += 2) // check sqrt(n)
        {
            if (num % i == 0)
            {
                is_prime = 0;
                break;
            }
        }

        if (is_prime)
        {
            count++;
            if (count == n)
                return num;
        }

        num += 2;
    }

    return num;
}

int main(void)
{
    printf("The 100th prime number is %d\n", prime(100));
    return 0;
}
