#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>

void compute_encryption(int k, char input[]);

int main(int argc, char *argv[])
{
    if(argc != 2)
    {
        printf("Usage: ./caesar key");
        return 1;
    }
    else
    {
        for(int i = 0; argv[1][i] != '\0'; i++)
        {
            if(argv[1][i] >= '0' && argv[1][i] <= '9')
            {
                continue;
            }
            else
            {
                printf("Usage: ./caesar key");
                return 1;
            }
        }
    }
    
    int k = atoi(argv[1]);

    char input[1000];

    printf("Plaintext: ");
    fgets(input, sizeof(input), stdin);

    compute_encryption(k, input);

    return 0;
}

void compute_encryption(int k, char input[])
{
    char output[1000];
    int i;

    for(i = 0; input[i] != '\0'; i++)
    {
        if(input[i] >= 'A' && input[i] <= 'Z')
        {
            output[i] = (input[i] - 'A' + k) % 26 + 'A';
        }
        else if(input[i] >= 'a' && input[i] <= 'z')
        {
            output[i] = (input[i] - 'a' + k) % 26 + 'a';
        }
        else
        {
            output[i] = input[i];
        }
    }
    output[i] = '\0';

    printf("Ciphertext: %s", output);
    

}