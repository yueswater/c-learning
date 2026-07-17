#include <stdio.h>

int isSunZhi(int x)
{
    if (x % 3 == 2 && x % 5 == 3 && x % 7 == 2)
        return 1;
    return 0;
}

int find(int n)
{
    int count = 0;
    for (int x = 0;; x++)
    {
        if (isSunZhi(x))
        {
            count++;
            if (count == n)
            {
                return x;
            }
        }
    }
}

int main(void)
{
    printf("The 5th integer in SunZhi is: %d\n", find(5));
    printf("The 7th integer in SunZhi is: %d\n", find(7));

    // Find first 12 integers meet SunZhi
    int count = 0;
    int currNum = 0;

    printf("The first 12 integers meet SunZhi are: ");
    while (count < 12)
    {
        if (isSunZhi(currNum))
        {
            if (count != 11)
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
