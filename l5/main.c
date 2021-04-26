#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main(int argc, char** argv)
{
    int x, y, z;
    scanf_s("%d%d%d", &x, &y, &z);
    printf_s("%d + %d + %d = %d\n", x, y, z, x+y+z);
    return 0;
}