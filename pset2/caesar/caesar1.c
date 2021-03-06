#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>

int main(int argc, string argv[])   //Cipher to encode messages using a key, second successful implementation modified from caesar0.c
{
    if (argc != 2) //complains about the wrong number of arguments entered and returns 1 for error
    {
        printf("One argument only!\n");
        return 1;
    }
    string plaintext = get_string("plaintext: ");
    int n = 0;
    printf("ciphertext: ");
    while (plaintext[n] != '\0') //keeps working so long as the end of the string is not reached
    {
        if (isupper(plaintext[n]))  //rotates uppercase characters
        {
            char plainupper = (plaintext[n] + (atoi(argv[1]) % 26));
            if (plainupper > 'Z')
            {
                plainupper -= ('[' - 'A');  //loops back after Z
            }
            printf("%c", plainupper);
        }
        else if (islower(plaintext[n]))
        {
            char plainlower = (plaintext[n] - ('a' - 'A') + (atoi(argv[1]) %
                               26));  //shifts lowercase letter to uppercase, because ASCII math, after the shift prints it as a lowercase
            if (plainlower > 'Z')
            {
                plainlower -= ('[' - 'A');  //loops back after Z
            }
            printf("%c", tolower(plainlower));
        }
        else   //keeps all non-letter characters the same
        {
            char plain_other = plaintext[n];
            printf("%c", plain_other);
        }
        n++;
    }
    printf("\n");
    return 0;
}
