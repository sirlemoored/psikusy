#include <stdio.h>

#include <palindrome.h>

int main()
{

	const char word1[] = "TommoT";
	const char word2[] = "TomAmoT";
	const char word3[] = "a";
	const char word4[] = "";
	const char word5[] = "AbcdrcbA";

	printf("%d\n", isPalindrome(word1));
	printf("%d\n", isPalindrome(word2));
	printf("%d\n", isPalindrome(word3));
	printf("%d\n", isPalindrome(word4));
	printf("%d\n", isPalindrome(word5));

	return 0;
}
