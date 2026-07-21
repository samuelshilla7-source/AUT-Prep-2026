#include <stdio.h>
#include <ctype.h>
#include <math.h>

int math_ops(char words[]);

int main(void)
{

    char words[1000];

    printf("Write your sentence : ");
    fgets(words, sizeof(words), stdin);

    math_ops(words);
    return 0;
}

int math_ops(char words[])
{
    int lettr = 0;
    int word = 1;
    int sentence = 0;

    for(int i = 0; words[i] != '\0'; i++)
    {
        char letter = toupper(words[i]);

        if(letter >= 'A' && letter <= 'Z')
        {
            lettr += 1;
        }
        else if(words[i] == ' ')
        {
            word += 1;
        }
        else if(words[i] == '.' || words[i] == '!' || words[i] == '?')
        {
            sentence += 1;
        } 

    }

    float L = (float)lettr/ word * 100;

    float S = (float)sentence/ word  * 100;

    float index = 0.0588 * L - 0.296 * S - 15.8;

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
        printf("Grade %d", grade);
    }
return grade;
}