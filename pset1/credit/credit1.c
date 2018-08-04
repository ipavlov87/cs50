/*
Determines validity of a credit card number and issuer, an improvement over credit0.c,
completes checksum using one for-loop instead of two.
*/

#include<cs50.h>
#include<math.h>
#include<stdio.h>

int main(void)
{
    long long cnumber;    //declare credit card number variable
    long long checksum = 0;  //checksum value

    do  //prompts user for a credit card number
    {
        cnumber = get_long_long("Credit Card Number: ");
    }
    while (cnumber < 0);

    for (long long digits = cnumber; digits > 0;
         digits = (digits / 10))  //starts checksum using Luhn’s algorithm
    {
        checksum += digits % 10;

        digits /= 10;

        if ((2 * (digits % 10) < 10))
        {
            checksum += 2 * (digits % 10);
        }
        else if ((2 * (digits % 10) >= 10))
        {
            checksum += (2 * (digits % 10) / 10 + ((2 * (digits % 10) % 10)));
        }
    }

    if ((checksum % 10 == 0) && ((34 * pow(10, 13) <= cnumber && cnumber < 35 * pow(10, 13)) || (37 * pow(10, 13) <= cnumber
                                 && cnumber < 38 * pow(10, 13)))) //works only if credit card number entered is possible valid AmEx
    {
        printf("AMEX\n");
    }
    else if ((checksum % 10 == 0) && (51 * pow(10, 14) <= cnumber
                                      && cnumber < 56 * pow(10, 14))) //works only if credit card number entered is possible valid MasterCard
    {
        printf("MASTERCARD\n");
    }
    else if ((checksum % 10 == 0) && ((4 * pow(10, 12) <= cnumber && cnumber < 5 * pow(10, 12)) || (4 * pow(10, 15) <= cnumber
                                      && cnumber < 5 * pow(10, 15)))) //works only if credit card number entered is possible valid Visa
    {
        printf("VISA\n");
    }
    else
    {
        printf("INVALID\n");    //number entered is not a valid credit card
    }
    return 0;
}
