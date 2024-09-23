#include "../include/utils.h"

int rsa_pub(int m, int e, int n)
{
    return mod_exp(m, e, n);
}

int rsa_priv(int m, int d, int n)
{
    return mod_exp(m, d, n);
}

