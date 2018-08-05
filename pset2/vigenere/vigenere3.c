#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, string argv[])   //Cipher to encode messages using a string of letters, simplified from attempt #4
{
    if (argc != 2) //complains about the wrong number of arguments entered and returns 1 for error
    {
        printf("One argument only!\n");
        return 1;
    }

    string key = argv[1];   //sets the first argument as the "key"

    for (int n = 0; n < strlen(key); n++)   //checks to make sure the key is only alphabetical letters
    {
        if (!isalpha(key[n]))
        {
            printf("Your key needs to be only letters!\n");
            return 1;
        }
    }

    string plaintext = get_string("plaintext:  ");   //promt for plaintext
    printf("ciphertext: "); //start of cipher text output
    char cipherchar;    //declares cipher character
    char q; //context for uppercase vs lowercase shift

    for (int o = 0, p = 0; o < strlen(plaintext); o++)  //starts the cipher at position 0 in the plaintext
    {
        if (!isalpha(plaintext[o]))    //keeps anything that is not a letter as it is
        {
            cipherchar = plaintext[o];
        }
        else if (isalpha(plaintext[o])) //applies cipher and advances to next character in key
        {
            if (islower(plaintext[o]))  //takes lower-case shift into context
            {
                q = 'a';
            }
            else if (isupper(plaintext[o])) //takes upper-case shift into context
            {
                q = 'A';
            }
            cipherchar = ((plaintext[o] - q + (toupper(key[p]) - 'A')) % 26) + q;
            p = (p + 1) % strlen(key);  //cycles to the next character in the key
        }
        printf("%c", cipherchar);   //prints out encrypted character
    }
    printf("\n");
    return 0;
}
