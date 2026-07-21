#include <stdio.h>
#include <ctype.h>

int compute_score(char word[]);

int main(void)
{

    char word1[100];
    char word2[100];

    printf("Player 1 :");

    fgets(word1, sizeof(word1), stdin);

    printf("Player 2 :");

    fgets(word2, sizeof(word2), stdin);

    int score1 = compute_score(word1);
    int score2 = compute_score(word2);

    if(score1 > score2)
    {
        printf("Player 1 wins!");
    }
    else if(score1 < score2)
    {
        printf("Player 2 wins!");
    }
    else
    {
        printf("Tie!");
    }
return 0;
}

int compute_score(char word[])
{
    int total = 0;

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
    
    for(int i = 0; word[i] != '\0'; i++)
    {

        char letter = toupper(word[i]);
        if(letter >= 'A' && letter <= 'Z')
        {

            total += points[letter - 'A'];
        }
    }
    return total;
}