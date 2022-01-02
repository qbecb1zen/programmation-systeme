#include <stdio.h>

int factoriel(int n)
{
    int n_factoriel = 1;
    for (int i = 1; i < n + 1; i++)
    {
        n_factoriel = n_factoriel * i;
    }
    return n_factoriel;
}

int main()
{
    printf("6 factoriel est égal à: %d\n", factoriel(6));
    return 0;
}
