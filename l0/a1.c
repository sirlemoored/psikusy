#include <stdio.h> 
#include <math.h>

#include <windows.h>

int main(int argc, char** argv)
{

    SetConsoleOutputCP(65001);
    float a1, a2, a3, b1, b2, b3;
    float detA, detX, detY;

    printf("\nPodaj współczynniki: \n> ");
    if(!scanf_s("%f %f %f %f %f %f", &a1, &a2, &a3, &b1, &b2, &b3))
    {
        printf("\nKatastrofalny błąd przy wprowadzaniu danych!!!\n");
        return -1;
    }

    detA = a1 * b2 - b1 * a2;
    detX = a3 * b2 - b3 * a2;
    detY = a1 * b3 - b1 * a3;
    if(detA == 0.0f)
    {
        printf("\n | Wyznacznik główny == 0.\n");
        if (detX != 0.0f || detY != 0.0f)
            printf(" | Układ równań sprzeczny.\n");
        else
            printf(" | Układ równań nieoznaczony.\n");
    }
    else
    {
        float x = detX / detA;
        float y = detY / detA;

        printf("\n | Układ oznaczony.\n");
        printf(" | x = %.2g\n | y = %.2g\n\n", x, y);
    }
    

    return 0;
}