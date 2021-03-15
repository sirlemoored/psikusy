#include <stdio.h>

int main(int argc, char** argv)
{
    int size;

    printf("Podaj liczbe: \n> ");
    if (!scanf_s("%d", &size))
    {
        printf("\nKatastrofalny blad przy wprowadzaniu danych!!!\n");
        return -1;
    }

    for (int i = 0; i < size; i++)
    {
        int stars = i+1;
        int spaces = size - stars;

        for (int j = 0; j < spaces; j++)
            printf(" ");
        else
            for (int j = 0; j < 2 * stars - 1; j++)
                printf("*");
        
        printf("\n");
    }       
    return 0;
}