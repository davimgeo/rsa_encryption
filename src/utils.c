#include "../include/utils.h"
#include "../include/gcd.h"

int find_e(int phi)
{
    int e = 2;
    while (gcd(e, phi) != 1 && e < phi)
    {
        e++;
    }
    return e;
}

int find_d(int e, int phi)
{
    int x;
    int gcd = extended_gcd(e, phi, &x);
    if (gcd != 1)
    {
        return -1;
    }
    return ((x % phi) + phi) % phi;
}

int mod_exp(int base, int exp, int mod)
{
    int result = 1;
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
