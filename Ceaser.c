/*
 !Design and implement a program, caesar, that encrypts messages using Caesar’s cipher.
*/

#include <cs50.h>
#include <ctype.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

bool only_digits(string input);
char rotate(char c, int key);

int main(int argc, string argv[])
{
    string plain_text;
    int length;
    char cipher_text;
    int key;
    bool has_only_digits;

    if (argc != 2)
    {
        printf("Usage: ./caesar key\n");
        return 1;
    }
    else
    {
        has_only_digits = only_digits(argv[1]);
        if (has_only_digits)
        {
            key = atoi(argv[1]);
            plain_text = get_string("plaintext: ");
        }
        else
        {
            printf("Usage: ./caesar key\n");
            return 1;
        }
    }
    printf("ciphertext: ");
    for (int k = 0; plain_text[k] != '\0'; k++)
    {
        cipher_text = rotate(plain_text[k], key);
        printf("%c", cipher_text);
    }
    printf("\n");
    return 0;
}

bool only_digits(string input)
{
    int length = strlen(input);

    for (int i = 0; i < length; i++)
    {
        if (isdigit(input[i]))
        {
            continue;
        }
        else
        {
            return false;
        }
    }
    return true;
}

char rotate(char c, int key)
{
    char output;

    if (isalpha(c))
    {
        if (isupper(c))
        {
            output = (((c - 65) + key) % 26) + 65;
        }
        else
        {
            output = (((c - 97) + key) % 26) + 97;
        }
    }
    else
    {
        output = c;
    }
    return output;
}