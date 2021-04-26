#include <iostream>
#include <cstdlib>

int main(int argc, char** argv)
{
    int* v = (int*)std::malloc(10 * sizeof(int));
    int* arr = new int[10];
    delete[] arr;
    return 0;
}