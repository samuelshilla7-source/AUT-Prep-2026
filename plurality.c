#include <stdio.h>
#include <string.h>
#include <stdbool.h>

typedef struct
{
    char name[100];
    int votes; 
}candidate;

candidate persons[9];
int candidate_count;
int n;

bool vote(char input[]);

void print_winner();

int main(int argc, char *argv[])
{
    if(argc > 10)
    {
        printf("Usage: ./plurality [candidate...]");
        return 1;
    }

    if(argc <= 1)
    {
        printf("Usage: ./plurality [candidate...]");
        return 1;
    }

    candidate_count = argc - 1;
    for (int i = 0; i < argc - 1; i++)
    {
        strcpy(persons[i].name, argv[i + 1]);
        persons[i].votes = 0;
    }

        printf("Number of voters: ");
        scanf("%d", &n);
        getchar();
    
   

    for(int i = 0; i < n; i++)
    {
         char input[100];
        
        printf("Vote: ");
        fgets(input, sizeof(input), stdin);
        input[strcspn(input, "\n")] = '\0';
        vote(input);
    }

    print_winner();
    return 0;
}

bool vote(char input[])
{
    for(int i = 0; i < candidate_count; i++)
    {
       if(strcmp(input, persons[i].name) == 0)
       {
         persons[i].votes += 1;
         return true;
       }
    } 
    printf("Invalid Vote\n");
    return false;
}

void print_winner()
{
    int high_score = 0;
    for(int i = 0; i < candidate_count; i++)
    {
        if(persons[i].votes > high_score)
        {
            high_score = persons[i].votes;
        }
    }

    for(int i = 0; i < candidate_count; i++)
        {
            if(high_score == persons[i].votes)
            {
                printf("%s\n", persons[i].name);
            }
        }
}



