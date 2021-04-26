#include <stdio.h>
#include <stdlib.h>

int** matrixAllocate(int n)
{
    int** rows = calloc(n, sizeof(int*));
    if (rows == NULL)
        return NULL;
    
    for (int i = 0; i < n; i++)
    {
        rows[i] = calloc(n, sizeof(int));
        if (rows[i] == NULL)
        {
            for (int j = 0; j < i; j++)
                free(rows[j]);
            return NULL;
        }
    }

    return rows;
}

void matrixFree(int n, int** arr)
{
    for (int i = 0; i < n; i++)
        free(arr[i]);
    free(arr);
}

void matrixFill(int n, int** arr)
{
    printf_s("The program will now ask for %d integer inputs.\n", n*n);
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            int scan;
            scanf_s("%d", &scan);
            if (scan != 0)
                scan = 1;

            arr[i][j] = scan;
        }
    }
}

void matrixPrint(int n, int** arr)
{
    for (int i = 0; i < n; i++)
    {
        printf_s(" | ");
        for (int j = 0; j < n; j++)
            if (j != 0)
                printf_s("%5d", arr[i][j]);
            else
                printf_s("%2d", arr[i][j]);
        printf_s(" | \n");
    }
}

int isMatrixReflexive(int n, int** arr)
{
    for (int i = 0; i < n; i++)
        if (arr[i][i] == 0)
            return 0;

    return 1;
}

int isMatrixSymmetric(int n, int** arr)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < i; j++)
            if (arr[i][j] != arr[j][i])
                return 0;
    }
    return 1;
}

int isMatrixTransitive(int n, int** arr)
{
    for (int x = 0; x < n; x++)
    {
        for (int y = 0; y < n; y++)
        {
            for (int z = 0; z < n; z++)
            {
                if (arr[x][y] != 0 && arr[y][z] != 0 && arr[x][z] == 0)
                    return 0;
            }
        }
    }
    return 1;
}

int main(int argc, char** argv)
{
    int size = atoi(argv[1]);
    if (size < 1)
        return -1;
    int** matrix = matrixAllocate(size);
    matrixFill(size, matrix);
    matrixPrint(size, matrix);
    printf_s("Reflexivity: %d\nSymmetry: %d\nTransitivity: %d\n", isMatrixReflexive(size, matrix), isMatrixSymmetric(size, matrix), isMatrixTransitive(size, matrix));
    matrixFree(size, matrix);
    return 0;
}