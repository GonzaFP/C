/**
 * !Design and implement a program, substitution, that encrypts messages using a substitution cipher.
*/

#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <string.h>

int validate_key(string text);
char rotate(char c, string text);

int main(int argc, string argv[])
{
    string user_text;
    char cipher_text;

    if (argc != 2)
    {
        printf("Usage: ./substitution key\n");
        return 1;
    }
    else
    {
        int returntype = validate_key(argv[1]);
        if (returntype == 1)
        {
            return 1;
        }
    }
    user_text = get_string("plaintext: ");
    printf("ciphertext: ");

    for (int k = 0; user_text[k] != '\0'; k++)
    {
        cipher_text = rotate(user_text[k], argv[1]);
        printf("%c", cipher_text);
    }
    printf("\n");
    return 0;
}

int validate_key(string text)
{
    int length = strlen(text);

    // reject key with fewer or greater than 26 characters.

    if (length != 26)
    {
        printf("Key must contain 26 characters\n");
        return 1;
    }
    else
    {
        for (int j = 0; j < length; j++)
        {
            if (isalpha(text[j]))
            {
                // check if key has any repeated letters
                int frequency = 0;
                for (int k = 0; k < length; k++)
                {
                    if (toupper(text[j]) == toupper(text[k]))
                    {
                        frequency++;
                    }
                    else
                    {
                        continue;
                    }
                }
                if (frequency > 1)
                {
                    printf("Key must not contain repeated characters\n");
                    return 1;
                }
                else
                {
                    continue;
                }
            }
            else
            // reject alphanumeric key.
            {
                printf("Key must contain only alphabetic characters\n");
                return 1;
            }
        }
        return 0;
    }
}

char rotate(char c, string text)
{
    char output;
    int length = strlen(text);
    for (int i = 0; i < length; i++)
    {
       // ! convert letters from ASCII to values that match key index.
       // ! check case to match user's input.
        if (isalpha(c))
        {
            if (isupper(c))
            {
                output = toupper(text[c - 65]);
            }
            else
            {
                output = tolower(text[c - 97]);
            }
        }
        else
        {
            output = c;
        }
    }
    return output;
}