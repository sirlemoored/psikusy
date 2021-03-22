#include <math.h>
#include <stdio.h>
#include <stdlib.h>

int collatz(int n)
{
    if (n == 1)
        return 1;
    if (n % 2 == 0)
        return n / 2;
    else 
        return 3 * n + 1;
}

int main(int argc, char** argv)
{

    if (argc != 2)
    {
        printf("Invalid usage. Usage: <number>.\n");
        return -1;
    };

    int n = atoi(argv[1]);

    do 
    {
        printf("%d ", n);
        n = collatz(n);
    }
    while (n != 1);
    printf("%d\n", 1);
    

    return 0;
}