#include <stdio.h>
#include <ctype.h>

int math_compute(char word[]);

int main(void)
{
    char word[100];

    printf("Enter a word: ");
    fgets(word, sizeof(word), stdin);
    math_compute(word);

}

int math_compute(char word[])
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

int highest_score = 0;
int current_score = 0;
int found_letter = 0;
int count_score = 0;

   for(int i = 0; word[i] != '\0'; i++)
   {
    char letter = toupper(word[i]);

    if(letter >= 'A' && letter <= 'Z')
    {
        found_letter = 1;
        int letter_points = points[letter - 'A'];

        if(letter_points > highest_score)
        {
           highest_score = letter_points;
           count_score = 1;
        }
        else if(letter_points == highest_score)
        {
            highest_score = letter_points;
            count_score += 1;
        }
    }
   }
   
   if(found_letter == 0)
   {
    printf("Invalid Input");
   }
   else
   {
    printf("Highest Score : %d\n", highest_score);
    printf("Count : %d\n", count_score);
   }
   return highest_score;
}