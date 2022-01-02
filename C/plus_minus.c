#include <stdlib.h>
#include <stdio.h>
#define TRUE 1

int random_int()
{
    return rand() % 100;
}

int main()
{
    int int_input;
    int random_to_guess = random_int();
    printf("Entrez a entier: ");
    scanf("%d", &int_input);
    while (TRUE)
    {
        if (random_to_guess > int_input)
        {
            printf("Non, c’est plus haut.\n");
            printf("Entrez a entier: ");
            scanf("%d", &int_input);
        }
        else if (random_to_guess < int_input)
        {
            printf("Non, c’est plus bas\n");
            printf("Entrez a entier: ");
            scanf("%d", &int_input);
        }
        else
        {
            printf("C’est gagné!");
            return 0;
        }
    };
}
