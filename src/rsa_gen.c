#include "../include/utils.h"

long long rsaPub(long long m, long long e, long long n)
{
    return modExp(m, e, n);
}

long long rsaPriv(long long m, long long d, long long n)
{
    return modExp(m, d, n);
}

