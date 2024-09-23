#include "../include/gcd.h"

int gcd(int a, int b)
{
    while (b != 0)
    {
        int temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

int extended_gcd(int a, int b, int *x)
{
    int x0 = 1, x1 = 0;
    while (b != 0)
    {
        int q = a / b;
        int temp = b;
        b = a % b;
        a = temp;

        int tempX = x1;
        x1 = x0 - q * x1;
        x0 = tempX;
    }
    *x = x0;
    return a;
}

