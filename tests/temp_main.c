#include <stdio.h>
#include "../include/utils.h"
#include "../include/gen_key.h"
#include "../include/print_parameters.h"
#include "../include/rsa_gen.h"

int main(int argc, char *argv[])
{
    int p = 41;
    int q = 97;

    int n = p * q;

    int phi = (p - 1) * (q - 1);

    int e = find_e(phi);
    int d = find_d(e, phi);
    int x;

    export_rsa_pub_key(e, n);
    export_rsa_priv_key(d, n); 

    FILE *id_rsa_pub = fopen("data/id_rsa_pub.txt", "r");
    if (id_rsa_pub == NULL) 
    {
        printf("Error opening public key file!\n");
        return 1;   
    }

    int read_e, read_n;
    if (fscanf(id_rsa_pub, "%d %d", &read_e, &read_n) != 2) 
    {
        printf("Error reading public key values!\n");
        fclose(id_rsa_pub);
        return 1; 
    }

    fclose(id_rsa_pub);

    int m = 150;

    int crypto_msg = rsa_pub(m, read_e, read_n);
    int decrypto_msg = rsa_priv(crypto_msg, d, n);

    //remember to put a flag to debug
    print_parameters(p, q, e, d, phi, x, m, crypto_msg, decrypto_msg);

    

    return 0;
}
