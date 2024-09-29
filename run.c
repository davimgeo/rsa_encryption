#include <stdio.h>
#include "include/utils.h"
#include "include/gen_key.h"
#include "include/print_parameters.h"
#include "include/rsa_gen.h"

int main(int argc, char *argv[])
{

    FILE *pq = fopen("data/inputs/pq.txt", "r");
    if (pq == NULL) 
    {
        printf("Could not open the file!\n");
        return 1;   
    }

    long long read_p, read_q;
    if (fscanf(pq, "%lld %lld", &read_p, &read_q) != 2) 
    {
        printf("Error reading pq file!\n");
        fclose(pq);
        return 1; 
    }

    long long p = read_p;
    long long q = read_q;

    long long n = p * q;

    long long phi = (p - 1) * (q - 1);

    long long e = 65537;
    long long d = findD(e, phi);
    long long x;

    exportRsaPubKey(e, n);
    exportRsaPrivKey(d, n); 

    FILE *id_rsa_pub = fopen("data/outputs/id_rsa_pub.txt", "r");
    if (id_rsa_pub == NULL) 
    {
        printf("Error opening public key file!\n");
        return 1;   
    }

    long long read_e, read_n;
    if (fscanf(id_rsa_pub, "%lld %lld", &read_e, &read_n) != 2) 
    {
        printf("Error reading public key values!\n");
        fclose(id_rsa_pub);
        return 1; 
    }

    fclose(id_rsa_pub);

    long long m = 1050;

    long long crypto_msg = rsaPub(m, read_e, read_n);
    long long decrypto_msg = rsaPriv(crypto_msg, d, n);

    //remember to put a flag to debug
    printParameters(p, q, e, d, phi, x, m, crypto_msg, decrypto_msg);

    return 0;
}

