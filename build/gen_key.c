#include <stdio.h>
#include "../include/gen_key.h"

void export_rsa_pub_key(int e, int n)
{
  FILE *id_rsa_pub = fopen("data/id_rsa_pub.txt", "w");
  if (id_rsa_pub == NULL) 
  {
    printf("Error oppening file!\n");
    return;
  }

  fprintf(id_rsa_pub, "%d %d", e, n);

  fclose(id_rsa_pub);
}

void export_rsa_priv_key(int d, int n)
{
  FILE *id_rsa_priv = fopen("data/id_rsa.txt", "w");
  if (id_rsa_priv == NULL) 
  {
    printf("Error oppening file!\n");
    return;
  }

  fprintf(id_rsa_priv, "%d %d", d, n);

  fclose(id_rsa_priv);
}
