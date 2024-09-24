#include <stdio.h>
#include "../include/gen_key.h"

void export_rsa_pub_key(long long e, long long n)
{
  FILE *id_rsa_pub = fopen("data/outputs/id_rsa_pub.txt", "w");
  if (id_rsa_pub == NULL) 
  {
    printf("Error oppening file!\n");
    return;
  }

  fprintf(id_rsa_pub, "%lld %lld", e, n);

  fclose(id_rsa_pub);
}

void export_rsa_priv_key(long long d, long long n)
{
  FILE *id_rsa_priv = fopen("data/outputs/id_rsa.txt", "w");
  if (id_rsa_priv == NULL) 
  {
    printf("Error oppening file!\n");
    return;
  }

  fprintf(id_rsa_priv, "%lld %lld", d, n);

  fclose(id_rsa_priv);
}
