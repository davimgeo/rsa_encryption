#include "../include/utils.h"
#include "../include/gcd.h"

long long findE(long long phi)
{
    long long e = 2;
    while (gcd(e, phi) != 1 && e < phi)
    {
        e++;
    }
    return e;
}

long long findD(long long e, long long phi)
{
    long long x;
    long long gcd = extendedGcd(e, phi, &x);
    if (gcd != 1)
    {
        return -1;
    }
    return ((x % phi) + phi) % phi;
}

long long modExp(long long base, long long exp, long long mod)
{
    long long result = 1;
    base = base % mod;
    while (exp > 0)
    {
        if (exp % 2 == 1)
            result = (result * base) % mod;
        exp = exp >> 1;
        base = (base * base) % mod;
    }
    return result;
}
