#include <cs50.h>
#include <stdio.h>
#include <math.h>

int main(void)
{
    long num, num_copy;

    num = get_long("Number: ");    // Prompt for input

    int i = 1;
    int even_sum = 0;
    int odd_sum = 0;
    int total = 0;
    num_copy = num;

    while (num > 0) // Calculate checksum using while loop
    {
        if (i % 2 == 0) // when i (the digit placement) is even
        {
            int doubled_digit = num % 10 * 2; //create a new digit variable in case value after doubled is over 9
            if (doubled_digit <= 9)
            {
                even_sum += doubled_digit;
                num /= 10;
                i++;
            }
            else
            {
                int ones_value = doubled_digit - 10; //split the value that's over 9 into ones value and 1.
                doubled_digit = 1 + ones_value;
                even_sum += doubled_digit;
                num /= 10;
                i++;
            }
        }

        if (i % 2 != 0) //when i (the digit placement) is odd
        {
            odd_sum += num % 10;
            num /= 10;
            i++;
        }
    }

    total = even_sum + odd_sum;
    //printf("%i\n", total);

    //check if Total % 10 == 0
    if (total % 10 != 0)
    {
        printf("INVALID\n");
    }
    else
    {
        int first_two_digits;
        int number_of_digits = 0;
        while (num_copy > 100)
        {
            num_copy = num_copy / 10;
            number_of_digits++;
        }
        first_two_digits = num_copy;
        number_of_digits += 2;

        //printf("number of digits is %i\n" , number_of_digits);
        //printf("first two digit is %i\n", first_two_digits);

        if (number_of_digits == 13 || number_of_digits == 15 || number_of_digits == 16) //check digits
        {
            if (first_two_digits > 50 && first_two_digits < 56)
            {
                printf("MASTERCARD\n");
            }
            else if (first_two_digits == 34 || first_two_digits == 37)
            {
                printf("AMEX\n");
            }
            else if (first_two_digits > 39 && first_two_digits < 50)
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
}


