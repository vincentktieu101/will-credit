#include <cs50.h>
#include <stdio.h>

int main(void)
{
    // Obtain user input for credit card number
    long Number;
    do
    {
        Number = get_long("Number: ");
    }
    while (Number < 0);

    // Find first checksum
    // (sum of digits of twice every other digit from second to last)
    long Number2 = Number;
    long checkNum = Number;
    long checksum1 = 0;
    long checksum2 = 0;
    long subtractor;
    long adder;
    long counter = 10;

    do
    {
        subtractor = Number % (counter);
        adder = ((Number - subtractor) % (10 * counter));
        // Add the digits to create first checksum
        if (2 * adder / counter >= 10)
        {
            checksum1 = checksum1 + 1 + 2 * (adder / counter) % 10;
        }
        else
        {
            checksum1 = checksum1 + 2 * adder / counter;
        }
        Number = Number - subtractor - (adder);
        counter *= 100;
    }
    while (Number > 0);

    // Obtain second checksum
    // (sum of every other digit from last)
    counter = 10;
    do
    {
        adder = Number2 % (counter);
        subtractor = ((Number2 - adder) % (10 * counter));
        // Add the digits to create second checksum
        checksum2 = checksum2 + (adder / (counter / 10));
        Number2 = Number2 - subtractor - (adder);
        counter *= 100;
    }
    while (Number2 > 0);

    // Add both checksums and check if last digit = 0
    long check0 = checksum1 + checksum2;

    if (check0 % 10 == 0)
    {
        // Check for card type
        if ((checkNum - (checkNum % 1000000000000000)) / 1000000000000000 == 4)
        {
            printf("VISA\n");
        }
        else if ((checkNum - (checkNum % 100000000000000)) / 100000000000000 >= 51
        && (checkNum - (checkNum % 100000000000000)) / 100000000000000 <= 55)
        {
            printf("MASTERCARD\n");
        }
        else if ((checkNum - (checkNum % 10000000000000)) / 10000000000000 == 37
        e|| (checkNum - (checkNum % 10000000000000)) / 10000000000000 == 34)
        {
            printf("AMEX\n");
        }
        else if ((checkNum - (checkNum % 1000000000000)) / 1000000000000 == 4)
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