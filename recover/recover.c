#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
 
int main(int argc, char *argv[])
{
    if(argc != 2)
    {
        printf("Usage: ./recover [forensic image]");
        return 1;
    }

    FILE *cr = fopen(argv[1], "rb");
    if(cr == NULL)
    {
        printf("Could not open file");
        return 1;
    }

    FILE *img = NULL;

    int counter = 0;
    uint8_t bytes[512];
    while(fread(bytes, sizeof(bytes), 1, cr) == 1)
    {
        if(bytes[0] == 0xff && bytes[1] == 0xd8 && bytes[2] == 0xff && bytes[3] >= 0xe0 && bytes[3] <= 0xef)
        {
            char text[8];
            sprintf(text, "%03i.jpg", counter);
            counter += 1;

            if(img != NULL)
            {
                fclose(img);
            }

            img = fopen(text, "wb");

            if(img == NULL)
            {
                printf("Could not open file");
                return 1;
            }

            fwrite(bytes, sizeof(bytes), 1, img);
        }
        else
        {
            fwrite(bytes, sizeof(bytes), 1, img);
        }
    }

    fclose(cr);
    fclose(img);
}