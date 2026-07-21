#include <stdio.h>
#include <stdbool.h>
#include <string.h>

typedef struct
{
    char name[100];
    int votes;
    int score;
}student;

student students[100];

bool vote(int n, char vote_name[]);
void winner(int n);
int high_score(int n);
float average(int n);
void verdict(int n);

int main(int argc, char *argv[])
{
    int n;
   

    printf("Number of students: ");
    scanf("%d", &n);
    getchar();

    for(int i = 0; i < n; i++)
    {
        printf("Student %d: ", i+1);
        fgets(students[i].name, sizeof(students[i].name), stdin);
        students[i].name[strcspn(students[i].name, "\n")] = '\0';

        printf("%s score: ", students[i].name);
        scanf("%d", &students[i].score);
        getchar();

        students[i].votes = 0;
    }

    int v;

    printf("Number of voters: \n");
    scanf("%d", &v);
    getchar();

    for(int i = 0; i < v; i++)
    {
        char vote_name[100];

        printf("Vote: ");
        fgets(vote_name, sizeof(vote_name), stdin);
        vote_name[strcspn(vote_name, "\n")] = '\0';
        bool valid = vote(n, vote_name);
        if(valid == false)
        {
            printf("Invalid vote");
        }
    }

    winner(n);
    high_score(n);
    printf("Class average %.1f\n", average(n));
    verdict(n);

    return 0;
}

bool vote(int n, char vote_name[])
{
    for(int i = 0; i < n; i++)
    {
        if(strcmp(vote_name, students[i].name) == 0)
        {
            students[i].votes += 1;
            return true;
        }
    }
    return false;
}

void winner(int n)
{
    int highest_num = 0;

    for(int i = 0; i < n; i++)
    {
        if(students[i].votes > highest_num)
        {
            highest_num = students[i].votes;
        }
    }

    for(int i = 0; i < n; i++)
    {
        if(students[i].votes == highest_num)
        {
            printf("Election Result:\n Winner is %s\n", students[i].name);
        }
    }
}

int high_score(int n)
{
    int highest_score = 0;
    for(int i = 0; i < n; i++)
    {
        if(students[i].score > highest_score)
        {
            highest_score = students[i].score;
        }
    }

    for(int i = 0; i < n; i++)
    {
        if(students[i].score == highest_score)
        {
            printf("Highest score: %s with %d\n", students[i].name, students[i].score);
        }
    }

    return 0;
}
float average(int n)
{
    int sum = 0;
    for(int i = 0; i < n; i++)
    {
        sum += students[i].score;
    }

    float averge = (float)sum/n;

    return averge;
}

void verdict(int n)
{
    for(int i = 0; i < n; i++)
    {
        if(students[i].score >= 50)
        {
            printf("%s: Pass\n", students[i].name);
        }
        else
        {
            printf("%s: Fail\n", students[i].name);
        }
    }
}