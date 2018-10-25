#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

//saves JPGs

int main(int argc, char *argv[])
{
    // ensure proper usage
    if (argc != 2)
    {
        fprintf(stderr, "Usage: recover infile\n");
        return 1;
    }

    // remember filename
    char *infile = argv[1];

    // open input file
    FILE *inptr = fopen(infile, "r");
    if (inptr == NULL)
    {
        fprintf(stderr, "Could not open %s.\n", infile);
        return 2;
    }

    //define BYTE as an unsigned 8-bit integer
    typedef uint8_t  BYTE;

    //temorary storage buffer
    BYTE buffer[512];

    //buffer for the filename
    char filename[8];

    //set up outgoing file pointer
    FILE *pic = NULL;

    //create some counters
    int number_of_pics = 0;


    //start JPG search going 512 bytes at a time and writing them to a buffer
    while(fread(&buffer, sizeof(BYTE), 512, inptr) == sizeof(buffer))
    {
        //finds the first JPG
        if (buffer[0] == 0xff && buffer[1] == 0xd8 && buffer[2] == 0xff && (buffer[3] & 0xf0) == 0xe0)
        {
            //create the first file
            sprintf(filename, "%03d.jpg", number_of_pics);
            pic = fopen(filename, "w");

            //writes to the first file
            fwrite(&buffer, sizeof(BYTE), 512, pic);

            //read the next 512 bytes
            while(fread(&buffer, sizeof(BYTE), 512, inptr) == sizeof(buffer))
            {
                //is it the header to a new JPG?
                if (buffer[0] == 0xff && buffer[1] == 0xd8 && buffer[2] == 0xff && (buffer[3] & 0xf0) == 0xe0)
                {
                    //close current one
                    fclose(pic);
                    //keep track, add one to total number of JPGs
                    number_of_pics++;
                    //create next file
                    sprintf(filename, "%03d.jpg", number_of_pics);
                    pic = fopen(filename, "w");
                }

                //if another JPG was not found we write, i.e., we're still working on the current one
                fwrite(&buffer, sizeof(BYTE), 512, pic);
            }
            //close last JPG
            fclose(pic);
        }
    }

    // close infile
    fclose(inptr);

    return 0;
}
