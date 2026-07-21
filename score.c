#include <stdio.h>
#include <ctype.h>

int compute_max(char word[]);

int main(void)
{
    char word[100];

    printf("Write a word:");

    fgets(word, sizeof(word), stdin);

   
 return compute_max(word); 
}

int compute_max(char word[])
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
    int best = 0;
    char super = 0;

    for(int i = 0; word[i] != '\0'; i++)
    {
        char letter = toupper(word[i]);
        if(letter >= 'A' && letter <='Z')
        {
            int letter_points = points[letter - 'A'];
            if(letter_points > best)
            {
                best = letter_points;
                super = letter;
            }
        }
    }
    printf("Best Score : %d\n", best);
    printf("Best letter : %c\n", super);

return best;
}