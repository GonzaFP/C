/**
 * !Design and implement a program, readability, that computes the Coleman-Liau index of text.
    Your program must prompt the user for a string of text using get_string.
    Your program should count the number of letters, words, and sentences in the text. You may assume that a letter is any lowercase character from a to z or any uppercase character from A to Z, any sequence of characters separated by spaces should count as a word, and that any occurrence of a period, exclamation point, or question mark indicates the end of a sentence.
    Your program should print as output "Grade X" where X is the grade level computed by the Coleman-Liau formula, rounded to the nearest integer.
    If the resulting index number is 16 or higher (equivalent to or greater than a senior undergraduate reading level), your program should output "Grade 16+" instead of giving the exact index number. If the index number is less than 1, your program should output "Before Grade 1".
*/


#include <cs50.h>
#include <ctype.h>
#include <math.h>
#include <stdio.h>
#include <string.h>

int count_letters(string text);
int count_words(string text);
int count_sentences(string text);
int get_grade(int letter_number, int words_number, int sentence_number);

int main(void)
{
    string Text = get_string("Text: ");
    int letters = count_letters(Text);
    int words = count_words(Text);
    int sentences = count_sentences(Text);
    int grade = get_grade(letters, words, sentences);

    if (grade < 1)
    {
        printf("Before Grade 1\n");
    }
    else if (grade > 16)
    {
        printf("Grade 16+\n");
    }
    else
    {
        printf("Grade %d\n", grade);
    }
}

int count_letters(string text)
{
    int number_of_letters = 0;

    for (int i = 0; text[i] != '\0'; i++)
    {
        if (isalpha(text[i]))
        {
            number_of_letters++;
        }
        else
        {
            continue;
        }
    }
    return number_of_letters;
}

int count_words(string text)
{
    int number_of_spaces = 0;

    for (int i = 0; text[i] != '\0'; i++)
    {
        if (text[i] == 32)
        {
            number_of_spaces++;
        }
        else
        {
            continue;
        }
    }
    return number_of_spaces + 1;
}

int count_sentences(string text)
{
    int number_of_sentences = 0;
    for (int i = 0; text[i] != '\0'; i++)
    {
        if (text[i] == 33 || text[i] == 46 || text[i] == 63)
        {
            number_of_sentences++;
        }
        else
        {
            continue;
        }
    }
    return number_of_sentences;
}

int get_grade(int letter_number, int words_number, int sentence_number)
{
    float L = ((float) letter_number / words_number) * 100;
    float S = ((float) sentence_number / words_number) * 100;
    float index = (0.0588 * L - 0.296 * S - 15.8);
    return round(index);
}