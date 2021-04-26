#include <palindrome.h>

bool isPalindrome(const char* word)
{
    int length = strlen(word);

    for (int i = 0; i < length / 2; i++)
        if (word[i] != word[length - 1 - i])
            return false;

    return true;
}

