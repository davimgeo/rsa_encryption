#include <stdio.h>
// invert an array
int main(int argc, char *argv[])
{
  int arr[8] = {1, 2, 3, 4, 5, 6, 7, 8};

  int size_arr = sizeof(arr) / sizeof(arr[0]);

  for (int i = 0; i < size_arr / 2; ++i) 
  {
    int temp = arr[i];
    arr[i] = arr[size_arr - 1 - i];
    arr[size_arr - 1 - i] = temp;

    for (int j = 0; j < size_arr; ++j) 
    {
      printf("%d ", arr[j]);
    }
    printf("\n");
    }
  return 0;
}
