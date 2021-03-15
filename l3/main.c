#include <math.h>
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

int fibonacciAux(unsigned int num, int previous[])
{
    if (num == 1 || num == 2)
        return 1;

    if (previous[num - 1] != 0)
        return previous[num - 1];

    previous[num - 1] = fibonacciAux(num - 1, previous) + fibonacciAux(num - 2, previous);
    return previous[num - 1];

    return 0;
}

int fibonacci(unsigned int num)
{
    int* previous = calloc(num, sizeof(unsigned int));
    if (previous == NULL)
        return -1;
    
    previous[0] = 1;
    previous[1] = 1;

    int n = fibonacciAux(num, previous);
    free(previous);
    return n;
}


int main(int argc, char** argv) 
{
    if (argc != 2)
        printf("Invalid number of arguments. Usage: <number> \n");
    printf("Fibonacci(%s) = %d\n", argv[1], fibonacci(atoi(argv[1])));
    return 0;
}