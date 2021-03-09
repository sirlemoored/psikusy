#include <iostream>

const int ASIZE = 26;
const int ASCII_OFFSET = 65;

bool isVowel(const char c)
{
    return (c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U' || c == 'Y');
}

int getIndex(const char c)
{
    return c - ASCII_OFFSET;
}

bool containsConsonants(const std::string& word, 
                        const std::string& target)
{
    int letters[ASIZE] = {0};
    int count = 0;

    for (int i = 0; i < target.size(); i++)
    {
        if(!isVowel(target[i]))
        {
            letters[getIndex(target[i])]++;
            count++;
        }
    }


    for (int i = 0; i < word.size(); i++)
    {
        int index = getIndex(word[i]);

        if(letters[index] > 0)
        {
            letters[index] = std::max(letters[index] - 1, 0);
            count--;
        }

    }

    return count == 0;
}

int main(int argc, char** argv)
{
    if (argc != 3)
    {
        std::cerr << "Invalid use. Usage: <word> <consonants>" << '\n';
        return 1;
    }

    std::string word = argv[1];
    std::string target = argv[2];

    std::cout << containsConsonants(word, target) << '\n';

    return 0;
}