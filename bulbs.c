/**
 * ! A program that converts text into binary and prints the bits.
 * 
*/

#include <stdio.h>
#include <string.h>

int main (void)
{
 char message[] = "HI!";
 int length = strlen(message);
 int decimal[length];
 int binary[length];

 for (int i = 0; i < length; i++)
 {
  int bits[8];

  // ! copying the ASCII value of the given letter.
  decimal[i] = message[i];
  int count = 0;
  do
  {
   if (decimal[i] % 2 == 0)
   {
    bits[8 - count - 1] = 0;
    count++;
   }
   else
   {
    bits[8 - count - 1] = 1;
    count++;
   }
    decimal[i] = decimal[i] / 2;
  }
  while (count < 8);

// ! printing the bits.
  for (int j = 0; j < 8; j++)
  {
   printf("%d",bits[j]);
  }
  printf("\n");
 }
  printf("\n");
}