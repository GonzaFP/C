#include<stdio.h>

int main(void)
{
  for (int i = 1; i <= 100; i++)
  {
    if (i == 2)
    {
      printf("%i\n",i);
    }

    else
    {
      for (int j = 2; j < i; j++)
    {
      if (i % j == 0)
      {
        break;
      }
      else if (i % j > 0 && j != i - 1)
      {
        continue;
      }
      else if (i % j > 0 && j == i - 1)
      {
        printf("%i\n",i);
      }
      else
      {
        break;
      }
    }
    }
    
  }
  return 0;
}