#include <stdio.h>

#include <anagram.h>
#include <palindrome.h>

int main()
{

	printf("%10s | %-10s: %d\n", "darek", "kreda", 		isAnagram("darek", "kreda"));
	printf("%10s | %-10s: %d\n", "k", "k", 				isAnagram("k", "k"));
	printf("%10s | %-10s: %d\n", "TOMEK", "TOM", 		isAnagram("TOMEK", "TOM"));
	printf("%10s | %-10s: %d\n", "", "",			 	isAnagram("", ""));
	printf("%10s | %-10s: %d\n", "KREDA", "KREEA", 		isAnagram("KREDA", "KREEA"));
	printf("%10s | %-10s: %d\n", "tarapaty", "patytara",isAnagram("tarapaty", "patytara"));

	return 0;
}
