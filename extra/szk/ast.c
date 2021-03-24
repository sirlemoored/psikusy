#include <stdio.h>

const int MOONPHASE_FULL = 15;
const int MOONPHASE_NEW  = 0;
const int MOONPHASE_NONE = -1;

void outputPhase(int previous, int current)
{
    if (current == MOONPHASE_NEW)
        fprintf(stdout, "UP\n");
    else if (current == MOONPHASE_FULL)
        fprintf(stdout, "DOWN\n");
    else if (previous == MOONPHASE_NONE)
        fprintf(stdout, "UNKNOWN\n");
    else if (previous > current)
        fprintf(stdout, "DOWN\n");
    else // zakładając poprawność danych!!!
        fprintf(stdout, "UP\n");
}

int main(int argc, char** argv) 
{
    int ioFlag = 1;
    int count  = 0;

    ioFlag = fscanf(stdin, "%d", &count);

    if (ioFlag == 0)
    {
        fprintf(stderr, "Katastroficzny błąd!\n");
        return -1;
    }

    int current = -1, previous = -1;

    for (size_t i = 0; i < count; i++)
    {   
        previous = current;
        ioFlag = fscanf(stdin, "%d", &current);
        
        if (ioFlag == 0)
        {
            fprintf(stderr, "Katastroficzny błąd!\n");
            return -1;
        }
    }

    outputPhase(previous, current);
    return 0;
}