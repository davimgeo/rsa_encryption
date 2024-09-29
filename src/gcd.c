#include "../include/gcd.h"

long long gcd(long long a, long long b)
{
    while (b != 0)
    {
        long long temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

long long extendedGcd(long long a, long long b, long long *x)
{
    long long x0 = 1, x1 = 0;
    while (b != 0)
    {
        long long q = a / b;
        long long temp = b;
        b = a % b;
        a = temp;

        long long tempX = x1;
        x1 = x0 - q * x1;
        x0 = tempX;
    }
    *x = x0;
    return a;
}

