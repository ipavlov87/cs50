#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>

int main(int argc, string argv[])   //Cipher to encode messages using a key, further yet simplified from caesar2.c
{
    if (argc != 2) //complains about the wrong number of arguments entered and returns 1 for error
    {
        printf("One argument only!\n");
        return 1;
    }
    string plaintext = get_string("plaintext: ");
    printf("ciphertext: ");
    for (int n = 0; plaintext[n] != '\0'; n++)
    {
        char plainchar;
        if (isupper(plaintext[n]))  //if uppercase letter, applies cipher
        {
            plainchar = ((plaintext[n] - 'A' + atoi(argv[1])) % 26) + 'A';
        }
        else if (islower(plaintext[n]))  //if lowercase letter, applies cipher
        {
            plainchar = ((plaintext[n] - 'a' + atoi(argv[1])) % 26) + 'a';
        }
        else    //if not a alphabetic character, keeps it the same
        {
            plainchar = plaintext[n];
        }
        printf("%c", plainchar);    //prints encrypted characters
    }
    printf("\n");   //adds new line after encrypted message
    return 0;
}
