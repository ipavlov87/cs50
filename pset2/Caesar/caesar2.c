#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>

int main(int argc, string argv[])   //Cipher to encode messages using a key, further simplified from caesar1.c
{
    if (argc != 2) //complains about the wrong number of arguments entered and returns 1 for error
    {
        printf("One argument only!\n");
        return 1;
    }
    string plaintext = get_string("plaintext: ");
    printf("ciphertext: ");
    for (int n = 0; plaintext[n] != '\0'; n++) //keeps working so long as the end of the string is not reached
    {
        char plainchar;
        if (isalpha(plaintext[n]))  //rotates uppercase characters
        {
            if (islower(plaintext[n]))
            {
                plainchar = plaintext[n] + (atoi(argv[1])) % 26;
                if (plainchar > 'F' && plainchar < 'a')
                {
                    plainchar -= ('[' - 'A');
                }
                if (plainchar > 'Z')
                {
                    plainchar -= ('[' - 'A');
                }
            }
            else
            {
                plainchar = plaintext[n];
            }
            printf("%c", plainchar);
        }
    }
    printf("\n");
    return 0;
}
