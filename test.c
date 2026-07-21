#include <stdio.h>
#include <ctype.h>
#include <math.h>

int compute_grade(char words[]);

int main(void)
{
    char words[1000];

    printf("Write your sentence : ");
    fgets(words, sizeof(words), stdin);

    compute_grade(words);
    return 0;

}

int compute_grade(char words[])
{
    int letters = 0;
    int word = 1;
    int sentences = 0;

    for(int i = 0; words[i] != '\0'; i++)
    {
        char letter = toupper(words[i]);
        if(letter >= 'A' && letter <= 'Z')
        {
            letters += 1;
        }
        else if(words[i] == ' ')
        {
            word += 1;
        }
        else if(words[i] == '.' || words[i] == '!' || words[i] == '?')
        {
            sentences += 1;
        }
    }

    float L = (float)letters / word *100;
    float S = (float)sentences / word *100;
    float  index = 0.0588 * L - 0.296 * S - 15.8;

    int grade = round(index);

    if(grade >= 16)
    {
        printf("Grade 16+");
    }
    else if(grade < 1)
    {
        printf("Before Grade 1");
    }
    else
    {
        printf("Grade : %d", grade);
    }
    return grade;
}