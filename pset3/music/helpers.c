// Helper functions for music

#include <cs50.h>
#include <ctype.h>
#include <math.h>
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
    int semitones[] = {0, 2, -9, -7, -5, -4, -2};   //semitone distance from A4 for {A4, B4, C4, D4, E4, F4, G4}

    n = note[0] - 'A';  //calculcates semitone distance base note in 4th octave
    n = semitones[(int)n];  //assigns starting distance based on possible values in semitones array

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
