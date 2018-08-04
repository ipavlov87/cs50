#include<cs50.h>
#include<stdio.h>

/*

Simple credit card authenticity checker, works for some American Express, MasterCard, and Visa cards.

*/

int main(void)  // determines validity of a credit card number and issuer
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

    if ((checksum % 10 == 0) && ((34 * 10000000000000 <= cnumber && cnumber < 35 * 10000000000000) || (37 * 10000000000000 <= cnumber
                                 && cnumber < 38 * 10000000000000))) //works only if credit card number entered is possible valid AmEx
    {
        printf("AMEX\n");
    }
    else if ((checksum % 10 == 0) && (51 * 100000000000000 <= cnumber
                                      && cnumber < 56 * 100000000000000)) //works only if credit card number entered is possible valid MasterCard
    {
        printf("MASTERCARD\n");
    }
    else if ((checksum % 10 == 0) && ((4 * 1000000000000 <= cnumber && cnumber < 5 * 1000000000000) || (4 * 1000000000000000 <= cnumber
                                      && cnumber < 5 * 1000000000000000))) //works only if credit card number entered is possible valid Visa
    {
        printf("VISA\n");
    }
    else
    {
        printf("INVALID\n");    //number entered is not a valid credit card
    }
    return 0;
}
