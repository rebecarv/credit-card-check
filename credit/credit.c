#include <cs50.h>
#include <stdio.h>

long credit_card_number;
bool luhn_check(long card_number);

int main(void)
{
    do
    {
        credit_card_number = get_long("Number: ");
    }
    while (credit_card_number < 1);

    if (luhn_check(credit_card_number))
    {
        if ((credit_card_number >= 340000000000000 && credit_card_number < 350000000000000) ||
            (credit_card_number >= 370000000000000 && credit_card_number < 380000000000000))
        {
            printf("AMEX\n");
        }
        else if ((credit_card_number >= 5100000000000000 && credit_card_number < 5600000000000000))
        {
            printf("MASTERCARD\n");
        }
        else if ((credit_card_number >= 4000000000000 && credit_card_number < 5000000000000) ||
                 (credit_card_number >= 4000000000000000 && credit_card_number < 5000000000000000))
        {
            printf("VISA\n");
        }
        else
        {
            printf("INVALID\n");
        }
    }
    else
    {
        printf("INVALID\n");
    }
}

// Checksum using Luhn's algorithm
bool luhn_check(long card_number)
{
    int total_sum = 0;
    int digit_count = 0;

    while (card_number > 0)
    {
        int digit = card_number % 10;

        if (digit_count % 2 == 1)
        {
            digit *= 2;

            while (digit > 0)
            {
                total_sum += digit % 10;
                digit /= 10;
            }
        }
        else
        {
            total_sum += digit;
        }

        card_number /= 10;
        digit_count++;
    }

    return total_sum % 10 == 0;
}
