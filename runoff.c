#include <stdio.h>
#include <string.h>
#include <stdbool.h>

typedef struct
{
    char name[100];
    int votes;
    bool eliminated;
}candidate;

candidate persons[9];
int candidate_count;
int preferences[100][9];
int n;

bool vote(int i, int j, char input[]);
void tabulate();
int find_min();
bool is_tie(int minn);
void eliminate(int minn);
bool print_winner();

int main(int argc, char *argv[])
{
    if(argc > 10)
    {
        printf("Invalid number of candidates");
        return 1;
    }

    if(argc <= 1)
    {
        printf("Usage: ./runoff [candidate...]");
        return 1;
    }

    candidate_count = argc - 1;

    for(int i = 0; i < candidate_count; i++)
    {
        strcpy(persons[i].name, argv[i+1]);
        persons[i].votes = 0;
        persons[i].eliminated = false;
    }

    printf("Number of voters: ");
    scanf("%d", &n);
    getchar();

    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < candidate_count; j++)
        {
            char input[100];
            printf("Rank %d:", j+1);
            fgets(input, sizeof(input), stdin);
            input[strcspn(input, "\n")] = '\0';
            if(vote(i,j,input) == false)
            {
                printf("Invalid vote \n");
            }
        }
         printf("\n");
    }

    while(true)
    {
       for(int i = 0; i < candidate_count; i++)
       {
        persons[i].votes = 0;
       }

        tabulate();

        if(print_winner())
        {
            break;
        }

        int minn = find_min();

        if(is_tie(minn))
        {
            for(int i = 0; i < candidate_count; i++)
            {
                if(persons[i].eliminated == false)
                {
                    printf("%s\n", persons[i].name);
                }
            }
            break;
        }
        
        eliminate(minn);
    }
    return 0;

}

bool vote(int i, int j, char input[])
{
    for(int k = 0; k < candidate_count; k++)
    {
        if(strcmp(input, persons[k].name) == 0)
        {
            preferences[i][j] = k;
            return true;
        }
    }
    return false;
}

void tabulate()
{
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < candidate_count; j++)
        {
            int k;

            k = preferences[i][j];

            if(persons[k].eliminated == false)
            {
                persons[k].votes += 1;
                break;
            }
        }
    }
}

int find_min()
{
    int minn = 1000;

    for(int i = 0; i < candidate_count; i++)
    {
        if(persons[i].eliminated == false && persons[i].votes < minn)
        {
            minn = persons[i].votes;
        }
    }
    return minn;
}

bool is_tie(int minn)
{
    for(int i = 0; i < candidate_count; i++)
    {
        if(persons[i].eliminated == false && persons[i].votes != minn)
        {
            return false;
        }
    }
    return true;
}

void eliminate(int minn)
{
    for(int i = 0; i < candidate_count; i++)
    {
        if(persons[i].eliminated == false && persons[i].votes == minn)
        {
            persons[i].eliminated = true;
        }
    }
}

bool print_winner()
{
    for(int i = 0; i < candidate_count; i++)
    {
        if(persons[i].votes > n/2)
        {
            printf("%s\n", persons[i].name);
            return true;
        }
    }
     return false;
}