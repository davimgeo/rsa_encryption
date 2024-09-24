#include <stdio.h>
#include "../include/gcd.h"

void print_parameters(long long p, long long q, long long e, long long d, long long phi, long long x, long long m, long long crypto_msg, long long decrypto_msg)
{
    printf("======================================\n");
    printf("\tDebug Information:\n");
    printf("p: %lld\nq: %lld\n", p, q);
    printf("e: %lld\n", e);
    printf("phi: %lld\n", phi);
    printf("d: %lld\n", d);
    printf("ext_gcd: %lld\n", extended_gcd(e, phi, &x));
    printf("x0 value: %lld\n", x);
    printf("Mensagem original: %lld\n", m);
    printf("Mensagem criptografada: %lld\n", crypto_msg);
    printf("Mensagem descriptografada: %lld\n", decrypto_msg);  
    printf("======================================\n");
}
