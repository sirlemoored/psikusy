#include <anagram.h>

// We assume character passed is from range a-zA-Z (inclusive).
int asciiToIndex(char c)
{
    if (c >= 'a' && c <= 'z')
        return c - 'a';
    else
        return c - 'A';
}

// We assume words are of the same case and consist of english letters a-z or A-Z.
bool isAnagram(const char* word1, const char* word2)
{
    size_t len1 = strlen(word1), 
           len2 = strlen(word2);

    if (len1 != len2)
        return false;

    int counter[ALPHABET_SIZE] = {0};   // array to count occurence of each alphabet letter

    for (size_t i = 0; i < len1; i++)
    {
        int ci = asciiToIndex(word1[i]); // array index of ith letter of first word
        counter[ci]++;
        ci = asciiToIndex(word2[i]); // array index of ith letter of second word
        counter[ci]--;
    }

    for (size_t i = 0; i < ALPHABET_SIZE; i++)
        if (counter[i] != 0)
            return false;

    return true;
}
