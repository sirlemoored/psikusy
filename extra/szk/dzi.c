#include <math.h>
#include <stdio.h>
#include <stdlib.h>

long long int arithmetic(long long x, long long y)
{
    if (x > y)
        return 0;
    long long res = (x + y) * (y - x + 1);
    return res / 2;
}

long long int geometric(long long a1, long long n)
{
    long long res = a1 * (1 - (long long)pow(2, n));
    return res * -1;
}

long long int weirdSum(long long n)
{
    if (n <= 0)
        return 0;
    else
        return arithmetic(1, n) - 2 * geometric(1, (long long)floor(log2(n)) + 1);
}

int main(int argc, char** argv)
{
    /* 
        Najbardziej wydajne rozwiązanie opiera się na wykorzystaniu różnicy
        sum ciągów arytmetycznego i geometrycznego (Sa - 2 * Sg). Ale może
        się wydarzyć psikus w postaci overflow!
    */

    int ioFlag = 1;
    int count  = 0;

    ioFlag = fscanf(stdin, "%d", &count);

    if (ioFlag == 0)
    {
        fprintf(stderr, "Katastroficzny błąd!\n");
        return -1;
    }

    for (size_t i = 0; i < count; i++)
    {
        long long n = 0;
        ioFlag = fscanf(stdin, "%lld", &n);
        
        if (ioFlag == 0 || n < 0)
        {
            fprintf(stderr, "Katastroficzny błąd!\n");
            return -1;
        }

        fprintf(stdout, "%lld\n", weirdSum(n));
    }
    return 0;
}