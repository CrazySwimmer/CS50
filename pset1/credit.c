#include <cs50.h>
#include <stdio.h>

int get_last_digit(long number);
int get_checksum(long card_number);
int get_number_length(long number);
long truncate_last_digit(long number);
long long_pow(int base, int exponent);

int main(void)
{
    long card_number;
    do
    {
        card_number = get_long("Number: ");
    }
    while (card_number < 34);

    int checksum = get_checksum(card_number);
    int checksum_last_digit = get_last_digit(checksum);

    if (checksum_last_digit)
    {
        printf("INVALID\n");
    }
    else
    {
        int len = get_number_length(card_number);
        int brand_code = card_number / long_pow(10, len - 2);

        // if i == 15 and (34 or 37) --> AMEX
        if (len == 15 && (brand_code == 34 || brand_code == 37))
        {
            printf("AMEX\n");
        }
        // if i == 16 and [51 - 55] --> MASTERCARD
        else if (len == 16 && brand_code >= 51 && brand_code <= 55)
        {
            printf("MASTERCARD\n");
        }
        // if (i == 13 or i == 16) and [40 - 49] --> VISA
        else if ((len == 13 || len == 16) && brand_code >= 40 && brand_code <= 49)
        {
            printf("VISA\n");
        }
        else
        {
            printf("INVALID\n");
        }
    }
}


int get_last_digit(long number)
{
    return number % 10;
}


long truncate_last_digit(long number)
{
    return number / 10;
}


int get_number_length(long number)
{
    int len = 0;
    while (number > 0)
    {
        len++;
        number = truncate_last_digit(number);
    }
    return len;
}


int get_checksum(long card_number)
{
    // Implement Luhn’s Algorithm

    int digit, product_digit;
    int sum_even = 0;
    int sum_odd = 0;
    int i = 0;

    while (card_number > 0)
    {
        i++;
        digit = get_last_digit(card_number);
        card_number = truncate_last_digit(card_number);
        if (i % 2)
        {
            sum_odd += digit;
        }
        else
        {
            product_digit = digit * 2;
            sum_even += get_last_digit(product_digit);
            product_digit = truncate_last_digit(product_digit);
            sum_even += get_last_digit(product_digit);
        }
    }
    return sum_odd + sum_even;
}


long long_pow(int base, int exponent)
{
    long res = 1;
    for (int i = 0; i < exponent; i++)
    {
        res *= base;
    }
    return res;
}