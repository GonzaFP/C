//! second version of an algorithm that prints prime numbers in a given range

#include <stdio.h>
#include<stdbool.h>

bool prime(int number);

int main(void)
{
    int min = 1;

    int max = 100;

    for (int i = min; i <= max; i++)
    {
        if (prime(i))
        {
            printf("%i\n", i);
        }
    }
}

bool prime(int number)
{
    // TODO
    int j;

   //! divide number by numbers from 2 upto number - 1
   //! If remainder is 0 number isn't prime. else if j = number - 1 & remainder is not zero, number is prime.

    if (number == 2)
    {
        return true;
    }
    else
    {
        for (j = 2; j < number; j++)
        {
            if (number % j == 0)
            {
                break;
            }
            else if (number % j > 0 && j != number - 1)
            {
                continue;
            }
            else if (number % j > 0 && j == number - 1)
            {
                return true;
            }
        }
    }
    return false;
}
