#include <cs50.h>
#include <math.h>
#include <stdio.h>

int main(void)
{
    float change;   //declare "change"
    int coins = 0;      //declare "coins"
    int cents;      //declare "cents"
    do
    {
        change = get_float("Change: ");     //prompts user for change due
    }
    while (change < 0);     //ensures input is non-negative
    for (cents = (round(change * 100)); cents > 24; cents -= 25) //counts quarters
    {
        coins++;
    }
    for (; cents < 25 && cents > 9; cents -= 10)    //counts dimes
    {
        coins++;
    }
    for (; cents < 10 && cents > 4; cents -= 5)       //counts nickles
    {
        coins++;
    }
    for (; cents < 5 && cents > 0; cents -= 1)     //counts pennies
    {
        coins++;
    }
    printf("%i\n", coins);
}
