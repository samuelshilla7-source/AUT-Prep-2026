#include <stdio.h>
#include <stdlib.h>

void math_operations(int numbers[]);

int main(void)
{
    int numbers[5];

    for(int i = 0; i < 5; i++)
    {
        printf("Enter A Number: ");
        scanf("%d", &numbers[i]);
    }

    math_operations(numbers);
    return 0;
}

void math_operations(int numbers[])
{
    int sum = 0;
    int largest_number = 0;
    int smallest_number = 1000;
    int count = 0;
    int current_number = 0;
    float average = 0;
    int even = 0;
    int odd = 0;

    for(int i = 0; i < 5; i++)
    {
        current_number = numbers[i];
        count += 1;
        sum += numbers[i];

        if(current_number > largest_number)
        {
            largest_number = current_number;
        }
        if(current_number < smallest_number)
        {
            smallest_number = current_number;
        }
        
        
        if(numbers[i] % 2 == 0)
        {
            even += 1;
        }
        else
        {
            odd += 1;
        }
    }

    average = (float)sum/count;


    printf("Sum: %d\n", sum);
    printf("Average %.2f\n", average);
    printf("Largest number: %d\n", largest_number);
    printf("Smallest Number: %d\n", smallest_number);
    printf("Even: %d | Odd %d\n", even,odd);
}