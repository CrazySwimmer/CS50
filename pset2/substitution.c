#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <string.h>

void encrypt(string key, string text);
int validate_key(string key);

int main(int argc, string argv[])
{

    // Check number of inputs
    if (argc != 2)
    {
        printf("Usage: ./substitution key\n");
        return 1;
    }
    string key = argv[1];

    // Validate input key
    if (validate_key(key)) // if key is invalid
    {
        return 1;
    }

    // Get plaintext
    string plaintext = get_string("plaintext:  ");

    // Encrypt
    encrypt(key, plaintext);

    return 0;
}

void encrypt(string key, string text)
{
    char cipherchar;
    int pos;

    printf("ciphertext: ");

    for (int i = 0, n = strlen(text); i < n; i++)
    {
        if (isalpha(text[i]))
        {
            if (islower(text[i])) // encrypt lower
            {
                pos = text[i] - 97;
                cipherchar = tolower(key[pos]);
            }
            else // encrypt upper
            {
                pos = text[i] - 65;
                cipherchar = toupper(key[pos]);
            }
        }
        else // Do not replace (e.g., symbols and numbers)
        {
            cipherchar = text[i];
        }

        printf("%c", cipherchar);
    }
    printf("\n");
}

int validate_key(string key)
{
    const int KEY_LEN = 26;

    // Check length of input
    if (strlen(key) != KEY_LEN)
    {
        printf("Key must contain 26 characters.\n");
        return 1;
    }

    // Check for alphabetic characters only
    for (int i = 0; i < KEY_LEN; i++)
    {
        if ((isalpha(key[i])) == 0)
        {
            printf("Key must contain only alphabetical characters.\n");
            return 1;
        }
    }

    // Check for each letter only once
    int flag[KEY_LEN];
    for (int i = 0; i < KEY_LEN; i++) // Initialize array of zeros
    {
        flag[i] = 0;
    }

    int pos;
    for (int i = 0; i < KEY_LEN; i++)
    {
        pos = toupper(key[i]) - 65;
        if (flag[pos])
        {
            printf("The key must contain each letter only once.\n");
            return 1;
        }
        else
        {
            flag[pos] = 1;
        }
    }

    return 0;
}