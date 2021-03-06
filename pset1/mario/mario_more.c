//make pyramids a la mario

#include <cs50.h>
#include <stdio.h>

int main(void)
{
    int levels;     //decalre "levels"

    do
    {
        levels = get_int("Pyramid height, 0 - 23: ");   // Ask for height of pyramid from user
    }
    while (levels < 0 || levels > 23);    //limits input to 0 to 23

    for (int rowcount = 0; rowcount < levels; rowcount++)     //prints rows
    {
        for (int spacecount = levels - rowcount; spacecount > 1; spacecount--)     //prints spaces
        {
            printf(" ");
        }
        for (int blocks = 1; blocks + rowcount > 0; blocks--)     //prints half of blocks
        {
            printf("#");
        }
        printf("  ");   //add the "space of 2"
        for (int blocks = 1; blocks + rowcount > 0; blocks--)     //prints remaining half of blocks
        {
            printf("#");
        }
        printf("\n");   //goes to new line after printing blocks and spaces
    }
}
