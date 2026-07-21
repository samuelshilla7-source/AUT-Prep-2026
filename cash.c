#include <stdio.h>
#include <stdbool.h>


int compute_money(int number);

int main(void)
{
    int number;

    while(true)
    {
            printf("Change Owed: ");
            scanf("%d", &number);
            if(number >= 0)
            {
                break;
            }
            else
            {
                continue;
            }
            
        }
        
        compute_money(number);
        return 0;
    }


int compute_money(int number)
{
    int count = 0;
    
    while(true)
    {
        if(number >= 25)
    {
        number -= 25;
        count += 1;
    }
    else if(number >= 10 && number < 25)
    {
        number -= 10;
        count += 1;
    }
    else if(number >= 5 && number < 10)
    {
        number -= 5;
        count += 1;
    }
    else if(number >= 1 && number < 5)
    {
        number -= 1;
        count += 1;
    }
    else if(number == 0)
    {
        break;
    }  


}
printf("%d", count);
return count;
 }

    
