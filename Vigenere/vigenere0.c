#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, string argv[])   //Cipher to encode messages using a string of letters, successful attempt #1
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
    int p = 0;

    for (int o = 0; o < strlen(plaintext); o++)
    {
        if (!isalpha(plaintext[o]))    //keeps anything that is not a letter as it is
        {
            cipherchar = plaintext[o];
        }
        else if (islower(plaintext[o])) //applies cipher to the lower-case letter and advances to next character in key
        {
            cipherchar = ((plaintext[o] - 'a' + (tolower(key[p]) - 'a')) % 26) + 'a';
            p++;
        }
        else if (isupper(plaintext[o])) //applies cipher to the upper-case letter and advances to the next character in key
        {
            cipherchar = ((plaintext[o] - 'A' + (toupper(key[p]) - 'A')) % 26) + 'A';
            p++;
        }
        if (p == strlen(key))   //resets the key character counter when at the end of the key
        {
            p = 0;
        }
        printf("%c", cipherchar);   //prints out encrypted character
    }
    printf("\n");
    return 0;
}
