#include <cs50.h>
#include <ctype.h>
#include <math.h>
#include <stdio.h>

int count_letters(string text);
int count_words(string text);
int count_sentences(string text);

int main(void)
{
    // Get user input
    string text = get_string("Text: ");
    int n_letters = count_letters(text);
    int n_words = count_words(text);
    int n_sentences = count_sentences(text);

    // Compute index
    double L = (double) n_letters / (double) n_words * 100.0;
    double S = (double) n_sentences / (double) n_words * 100.0;
    int index = round(0.0588 * L - 0.296 * S - 15.8);

    // Output grade
    if (index >= 16)
    {
        printf("Grade 16+\n");
    }
    else if (index < 1)
    {
        printf("Before Grade 1\n");
    }
    else
    {
        printf("Grade %i\n", index);
    }
}

int count_sentences(string text)
{
    char c;
    int i = 0, cnt = 0;
    while (text[i] != '\0')
    {
        c = text[i];
        if (c == 46 || c == 33 || c == 63) // . or ! or ?
        {
            cnt++;
        }
        i++;
    }
    return cnt;
}

int count_words(string text)
{
    int i = 0, cnt = 0;
    while (text[i] != '\0')
    {
        if (isspace(text[i]))
        {
            cnt++;
        }
        i++;
    }
    cnt++; // Last word
    return cnt;
}

int count_letters(string text)
{
    int i = 0, cnt = 0;
    while (text[i] != '\0')
    {
        if (isalpha(text[i]))
        {
            cnt++;
        }
        i++;
    }
    return cnt;
}