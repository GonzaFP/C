// Write a function to replace vowels with numbers
// Get practice with strings
// Get practice with command line
// Get practice with switch

#include <cs50.h>
#include <stdio.h>

string replace(string input);

int main(int argc, string argv[])
{
   if (argc < 2 || argc > 2)
   {
    printf("Error: enter only one argument\n");
    return 1;
   }
   string word = replace(argv[1]);
   printf("%s\n", word);
   return 0;
}

string replace(string input)
{
    for (int i = 0; input[i] != '\0'; i++)
    {
        switch(input[i])
        {
            case 'a':
            input[i] = '6';
            break;

            case 'e':
            input[i] = '3';
            break;

            case 'i':
            input[i] = '1';
            break;

            case 'o':
            input[i] = '0';
            break;

            default:
            break;
        }
    }
        return input;
}