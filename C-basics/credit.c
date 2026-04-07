#include <stdio.h>

int count_digits(long long number){
    int count = 0;

    
    while (number > 0){

        number = number/10;
        count++;

    }
    return count;
}

int first_digit(long long number){

while (number >= 10){

    number = number/10;
    
}
return number;

}

int first_two_digits(long long number){

while (number >=100){
    number = number/10;
}
return number;

}

int luhn_check(long long number){

long long copy = number;

int sum = 0;

int position = 0;

int digit = 0;

while (copy > 0){
    digit = copy % 10;

    if (position % 2 != 0){
        digit *= 2;
        if (digit > 9){

        digit -= 9;
    }
    
    
}
    sum += digit;
    copy /= 10;
    position++;  
}
if (sum % 10 == 0){
    return 1;
}
else{
    return 0;
}
}


int main(void){

long long number;

printf("Enter Number\n");

scanf("%lld", &number);

int digits = count_digits(number);
int first = first_digit(number);
int first_two = first_two_digits(number);
int check = luhn_check(number);

    if (check != 1){
        printf("Invalid\n");
    }
    else if (digits == 15 && (first_two == 34 || first_two == 37)){
        printf("Amex\n");
    }
    else if(digits == 16 && (first_two >= 51 && first_two <=55)){
        printf("Mastercard\n");
    }
    else if ((digits == 13 || digits == 16) && first == 4){
        printf("Visa\n");
    }
    else{
        printf("Invalid\n");
    }



return 0;

}