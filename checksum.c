/**
 * ! program which checks if a given card number is valid.
 * ! If so, which type of card is it?
 * ! MasterCards have 16 digits & start with either 51 range
 * ! Visa has 13 or 16 digits and starts with 4.
 * !AMEX has 15 and starts with 34 0r 37.
*/

#include<stdio.h>
int main(void)
{
  //! intialize variables

  long long number = 4003600000000014;
  int sum = 0;
  int count = 0;
  int last_digit = 0;
  int first_digit;

/*
  !loop thru card digits. digits in even postions are added to sum. Those in odd are multiplied by 2 and the digits of product are added to sum
*/
  do
  {
    last_digit =  number % 10;

    //! Check if only two digits are remaining after chopping off the last digit.
    //! if so, store the two digits as first digits so that they can identity type of card.
    int temp = number;
    int test_number = number / 10;
    if (test_number > 0)
    {
      if (test_number == 4){
        first_digit = 4;
      }
      else{

      first_digit = temp;
      }
    }

    //! digit in even position is added to sum.
  if (count % 2 == 0)
  {
    sum += last_digit;
    count++;
    number = number / 10;
  }

  //! digit in odd position is multiplied by 2 then product digit is added to sum.
  else if (count % 2 > 0)
  
  {
   int product = last_digit * 2;
    do
    {
      int other_last_digit = product % 10;
      sum += other_last_digit;
      product = product / 10;
    }
    while (product > 0);
    number = number / 10;
    count++;
  }
  }
  while (number > 0);

  //! checking for validity and type of card.
  if (sum % 10 == 0)
  {
    if (count == 15 && (first_digit == 34 || first_digit == 37))
      {
        printf("AMEX\n");
      }
    else if (count == 16 && (first_digit == 51 || first_digit == 52 || first_digit == 52 || first_digit == 53 || first_digit == 54 || first_digit == 55))
      {
        printf("MASTERCARD\n");
      }
    else if ((count == 13 || count == 16) && (first_digit == 4 ))
      {
        printf("VISA\n");
      }
  }
  else
  {
    printf("INVALD\n");
  }
}