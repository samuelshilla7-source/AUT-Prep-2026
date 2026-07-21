#include <stdio.h>
#include <ctype.h>

int compute_score(char input[]);

int main(void)
{

    char input[100];

    printf("What is your word: ");
    fgets(input, sizeof(input), stdin);
    compute_score(input);
    return 0;
}

int compute_score(char input[])
{

    int points[26];
    {
         points[0] = 1;
        points[1] = 3;
        points[2] = 3;
        points[3] = 2;
        points[4] = 1;
        points[5] = 4;
        points[6] = 2;
        points[7] = 4;
        points[8] = 1;
        points[9] = 8;
        points[10] = 5;
        points[11] = 1;
        points[12] = 3;
        points[13] = 1;
        points[14] = 1;
        points[15] = 3;
        points[16] = 10;
        points[17] = 1;
        points[18] = 1;
        points[19] = 1;
        points[20] = 1;
        points[21] = 4;
        points[22] = 4;
        points[23] = 8;
        points[24] = 4;
        points[25] = 10;
    }
    
    int lowest = 11;
    char inferior = 0;
    int found_letter = 0;

    for(int i = 0; input[i] != '\0'; i++)
    {
        char letter = toupper(input[i]);

        if(letter >= 'A' && letter <= 'Z')
        {
            found_letter = 1;
            int letter_points = points[letter - 'A'];
            if(letter_points < lowest)
            {
                lowest = letter_points;
                inferior = letter;
            }
        }

    }
    if(found_letter == 0)
    {
        printf("Invalid Input");
    }
    else
    {
        printf("Lowest Score: %d\n", lowest);
        printf("Lowest Letter: %c\n", inferior);
    }
    

return lowest;
}