// Helper functions for music

#include <cs50.h>
#include <ctype.h>
#include <math.h>
#include <stdio.h>
#include <string.h>

#include "helpers.h"

// Converts a fraction formatted as X/Y to eighths
int duration(string fraction)   //
{
    int eighths;
    int numerator = fraction[0] - '0';  //top part of the fraction
    int denominator = fraction[2] - '0';    //bottom part of the fraction
    eighths = (8 * numerator) / denominator;    //determines number of eighths
    return eighths;
}

// Calculates frequency (in Hz) of a note

int frequency(string note)
{
    int hertz;
    float n = 0;    //total semitone distance from A4

    switch (note[0])    //gets "base" octave value for frequency calculation
    {
        case 'A' :
            n += -2;
        case 'B' :
            n += 11;
        case 'C' :
            n += -2;
        case 'D' :
            n += -2;
        case 'E' :
            n += -1;
        case 'F' :
            n += -2;
        case 'G':
            n += -2;
            break;
        default :
            printf("You shouldn't see this\n");
    }

    if (isdigit(note[1]))   //factors in the distance of the octave, if no "#" or "b" is present
    {
        n += (note[1] - '4') * 12;
    }
    else if (isdigit(note[2]))  //factors in the distance of the octave, if "#" or "b" is present
    {
        n += (note[2] - '4') * 12;
    }

    if (note[1] == '#') //factors in the change for "#"
    {
        n++;
    }
    else if (note[1] == 'b')    //factors in the change for "b"
    {
        n--;
    }

    hertz = round(pow(2, (n / 12)) * 440);  //rounds frequency to nearest whole integer
    return hertz;
}

// Determines whether a string represents a rest
bool is_rest(string s)
{
    if (strlen(s) == 0) //checks for a strlen() of zero
    {
        return true;
    }
    else
    {
        return false;
    }
}
