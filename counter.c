#include <stdio.h>
#include <ctype.h>
#include <string.h>

int counters(char input[]);

int main(void)
{
    char input[1000];

    printf("Write your sentence: ");
    fgets(input, sizeof(input), stdin);
    input [strcspn(input, "\n")] = '\0';
    counters(input);
    return 0;
}

int counters(char input[])
{
    int characters = 0;
    int words = 1;
    int longest_length = 0;
    int current_length = 0;

    for(int i = 0; input[i] != '\0'; i++)
    {
        if(input[i] != ' ')
        {
            characters += 1;
            current_length += 1;
        }
        else if(input[i] == ' ')
        {
            words += 1;
            if(current_length > longest_length)
            {
                longest_length = current_length;
            }
            current_length = 0;
        }
    }
    if(current_length > longest_length)
    {
        longest_length = current_length;
    }

    printf("Words: %d\n", words);
    printf("Characters (no space): %d\n", characters);
    printf("Longest Word: %d Letters\n", longest_length);

}