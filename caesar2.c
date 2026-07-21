#include <stdio.h>
#include <stdlib.h>

void compute_encryption(int k, char input[]);

int main(int argc, char *argv[])
{
    if(argc != 2)
    {
        printf("Usage: ./caesar2 Key");
        return 1;
    }

    for(int i = 0; argv[1][i] != '\0'; i++)
    {
        if(argv[1][i] >= '0' && argv[1][i] <= '9')
        {
            continue;
        }
        else
        {
            printf("Usage: ./caesar2 Key");
            return 1;
        }
    }

    int k = atoi(argv[1]);

    char input[1000];
    
    printf("Plaintext: ");
    fgets(input, sizeof(input), stdin);

    compute_encryption(k, input);
}

void compute_encryption(int k, char input[])
{
    char output[1000];
    int i = 0;

    for(i = 0; input[i] != '\0'; i++)
    {
        if(input[i] >= 'a' && input[i] <= 'z')
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