#include <math.h>
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

bool isPrime(unsigned int num)
{
    if (num == 2)
        return true;

    if (num % 2 == 0)
        return false;

    for (int i = 3; i * i <= num; i += 2)
    {
        if (num % i == 0)
            return false;
    }

    return true;
}


int main(int argc, char** argv) 
{
    if (argc != 2)
        printf("Invalid number of arguments. Usage: <number> \n");
    printf("Primality of %s: %d\n", argv[1], isPrime(atoi(argv[1])));
    return 0;
}