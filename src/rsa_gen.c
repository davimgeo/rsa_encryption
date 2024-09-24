#include "../include/utils.h"

long long rsa_pub(long long m, long long e, long long n)
{
    return mod_exp(m, e, n);
}

long long rsa_priv(long long m, long long d, long long n)
{
    return mod_exp(m, d, n);
}

