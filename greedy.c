// program that prints smallest number of coins with which change can be made.

#include<stdio.h>

int main (void)
{
  int change = 99;
  int count = 0;

  int coins[] = {25,10,5,1};

  for (int i = 0; i < 4; i++)
  {
   if (change < coins[i])
   {
    continue;
   }
   else if (change >= coins[i])
   {
    do
    {
     change = change - coins[i];
     count++;
    }
    while (change >= coins[i]);
   }
  } 
  printf("Count %i\n",count);

}