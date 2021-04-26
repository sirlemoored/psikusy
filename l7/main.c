#include <stdio.h>
#include <string.h>

int isLetterRemoved(const char* original, const char* removed)
{
    int length = strlen(original);
    int offset = 0;
    for (int i = 0; offset <= 1 && i + offset < length; i++)
        if (original[i + offset] != removed[i])
            offset++;

    return offset == 1;

}

int main(int argc, char** argv)
{
    char orig[30], remov[30];
    scanf("%s %s", orig, remov);
    int skrotka = isLetterRemoved(orig, remov);
    printf_s("Oryginalny ciag znakow: %s\nCiag znakow testowy: %s\nCzy jest skrotka: %d\n", orig, remov, skrotka);   
    return 0;
}
