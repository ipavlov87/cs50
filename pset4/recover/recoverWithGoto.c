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

    int number_of_pics = 0;
    int number_of_blocks = 0;

    LOOP1:
    while(fread(&buffer, sizeof(BYTE), 512, inptr) == sizeof(buffer))
    {
        number_of_blocks++;

        if (buffer[0] == 0xff && buffer[1] == 0xd8 && buffer[2] == 0xff && (buffer[3] & 0xf0) == 0xe0)
        {
            number_of_pics++;
            /*
            - create new JPG file - name structure "###.JPG"
            - write to new JPG file
            - read next 512 byte block
            - if it starts with JPG-header, close previous file make next JPG in series
            - if it does not start with JPEG-header, append to current JPG file
            */

            //create files
            sprintf(filename, "%03d.jpg", number_of_pics);
            pic = fopen(filename, "w");

            fwrite(&buffer, sizeof(BYTE), 512, pic);

            LOOP2:
            fread(&buffer, sizeof(BYTE), 512, inptr);
            if (buffer[0] == 0xff && buffer[1] == 0xd8 && buffer[2] == 0xff && (buffer[3] & 0xf0) == 0xe0)
            {
                //go back to the start of the block
                fseek(inptr, -512*sizeof(BYTE), SEEK_CUR);
                //
                fclose(pic);
                //go back to the start
                goto LOOP1;
            }

            fseek(inptr, -512*sizeof(BYTE), SEEK_CUR);
            if (fread(&buffer, sizeof(BYTE), 512, inptr) == sizeof(buffer))
            {
                //continue to write to new jpg
                fwrite(&buffer, sizeof(BYTE), 512, pic);
                goto LOOP2;
            }
            else
            {
                goto LOOP1;
            }
        }
    }

    printf("%03d\n", number_of_pics);
    printf("%03d.jpg\n", number_of_pics);
    printf("Number of pics: %d\n", number_of_pics);
    printf("Number of blocks: %d\n", number_of_blocks);

    // close infile
    fclose(inptr);

    return 0;
}
