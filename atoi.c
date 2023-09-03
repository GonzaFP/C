/**
 * ! an implementation of atoi function using recursion.
*/

#include <cs50.h>
#include <ctype.h>
#include <math.h>
#include <stdio.h>
#include <string.h>

int convert(string input);

int main(void)
{
    // ! get sring of numbers from a user.

    string input = get_string("Enter a positive integer: ");

    // ! Reject a string with any non-digits.

    for (int i = 0, n = strlen(input); i < n; i++)
    {
        if (!isdigit(input[i]))
        {
            printf("Invalid Input!\n");
            return 1;
        }
    }

    // !Convert string to int
    printf("%i\n", convert(input));
}

int convert(string input)
{
    // TODO
    int length = strlen(input);
    int number = 0;

    //! base case, if only one element is left in the array
    if (length == 1)
    {
        return number = (number * 10) + (input[0] - '0');
    }

    // ! else convert last charcter into an interger by subtracting 0/48
    int last_number = input[length - 1] - '0';

    // ! Shorten the string.
    input[length - 1] = '\0';
    return number = (convert(input) * 10) + last_number;
}