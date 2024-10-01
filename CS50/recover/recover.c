#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

typedef uint8_t  BYTE;
 
int main(int argc, char *argv[])
{
    if (argc != 2)
    {
        printf("Invalid number of inputs. Plese input only one path to you file.");
        return 1;
    }

    // Name of recovery file
    char *infile = argv[1];

    // Open recovery file
    FILE *raw_file = fopen(infile, "r");
    if (raw_file == NULL)
    {
        printf("Could not open %s.\n", infile);
        return 2;
    }

    int block = 512;
    BYTE *buffer = malloc(block*sizeof(BYTE));
    //BYTE buffer[512]; also works

    if(buffer == NULL)
    {
        printf("Memory allocation failed.");
        return 3;
    }

    FILE *img = NULL;

    char filename[8]; // for naming
    int counter = 0;

    // I will read recovery file while there is still 512B blocks
    while (fread(buffer, sizeof(BYTE), block, raw_file) == block*sizeof(BYTE))
    {
        // checks if start of img in buffer
        if (buffer[0] == 0xff && buffer[1] == 0xd8 && buffer[2] == 0xff && (buffer[3] & 0xf0) == 0xe0)
        {
            // if start of img and first image i.e. counter ==0
            // then begins writing a new image
            if (counter == 0)
            {
                sprintf(filename, "%03i.jpg", counter);
                img = fopen(filename, "w");
                fwrite(buffer, sizeof(BYTE), block, img); //&buffer
                counter += 1;
            }
            // if start of img but not first image then
            // closes the image and begins writing new image
            else if (counter > 0)
            {
                fclose(img);
                sprintf(filename, "%03i.jpg", counter);
                img = fopen(filename, "w");
                fwrite(buffer, sizeof(BYTE), block, img); //&buffer
                counter += 1;
            }
        }
        // if not start of new img
        // then it keeps on writing the image
        else if (counter > 0)
        {
            fwrite(buffer, sizeof(BYTE), block, img); //&buffer
        }

    }

    fclose(raw_file);
    fclose(img);

    free(buffer);
    return 0;
}