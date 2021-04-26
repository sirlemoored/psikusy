#pragma once
#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <stdlib.h>

#define ALPHABET_SIZE 26

int asciiToIndex(char c);

bool isAnagram(const char* word1, const char* word2);
