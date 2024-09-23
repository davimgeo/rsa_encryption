#include <stdio.h>
#include <stdlib.h>

#define ARRAY_SIZE 255
#define BASE 64
#define ALPHABET "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz+/"

char* base64(int num)
{
    char *result = malloc(ARRAY_SIZE * sizeof(char));
    if (result == NULL) 
    {
        fprintf(stderr, "Memory allocation failed\n");
        return NULL;
    }

    int i = 0;
    while (num >= 1) 
    {
        result[i++] = ALPHABET[num % BASE];
        num /= BASE;
    }
    result[i] = '\0';

    for (int j = 0; j < i / 2; ++j) 
    {
        char temp = result[j];
        result[j] = result[i - 1 - j];
        result[i - 1 - j] = temp;
    }

    return result;
}

void print_binary(unsigned int n)
{
  while(n)
  {
    if (n & 1) 
    {
      printf("1");
    }
    printf("0");

    n >>= 1;
  }
  printf("\n");
}

int main(int argc, char *argv[])
{
    unsigned int num = 640;
    char* result = base64(num);

    if (result != NULL) 
    {
        printf("Base64: %s\n", result);
        free(result);     
    }

    print_binary(num);

    return 0;
}

