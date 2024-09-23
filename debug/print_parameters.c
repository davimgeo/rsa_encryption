#include <stdio.h>
#include "../include/gcd.h"

void print_parameters(int p, int q, int e, int d, int phi, int x, int m, int crypto_msg, int decrypto_msg)
{
    printf("\tDebug Information:");
    printf("p: %d\nq: %d\n", p, q);
    printf("e: %d\n", e);
    printf("d: %d\n", d);
    printf("ext_gcd: %d\n", extended_gcd(e, phi, &x));
    printf("x0 value: %d\n", x);
    printf("Mensagem original: %d\n", m);
    printf("Mensagem criptografada: %d\n", crypto_msg);
    printf("Mensagem descriptografada: %d\n", decrypto_msg);  
    printf("\n======================================\n");
}
