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
    int numerator = fraction[0] - '0';
    int denominator = fraction[2] - '0';
    eighths = (8 * numerator) / denominator;
    return eighths;
}

// Calculates frequency (in Hz) of a note

int frequency(string note)
{
    int hertz;
    float semitones = 0;

    if (note[0] == 'A')
    {
        semitones = 0;
    }
    else if (note[0] == 'B')
    {
        semitones = 2;
    }
    else if (note[0] == 'C')
    {
        semitones = -9;
    }
    else if (note[0] == 'D')
    {
        semitones = -7;
    }
    else if (note[0] == 'E')
    {
        semitones = -5;
    }
    else if (note[0] == 'F')
    {
        semitones = -4;
    }
    else if (note[0] == 'G')
    {
        semitones = -2;
    }

    if (isdigit(note[1]))
    {
        semitones += (note[1] - '4') * 12;
    }
    else if (isdigit(note[2]))
    {
        semitones += (note[2] - '4') * 12;
    }

    if (note[1] == '#')
    {
        semitones++;
    }
    else if (note[1] == 'b')
    {
        semitones--;
    }

    hertz = round(pow(2, (semitones / 12)) * 440);
    return hertz;
}

// Determines whether a string represents a rest
bool is_rest(string s)
{
    if (strlen(s) == 0)
    {
        return true;
    }
    else
    {
        return false;
    }
}
