#include <stdio.h>
#include <stdlib.h>

#include "stringUtil.h"


int len(const char* str) { // returns the length of str (excluding the terminating 0)
	int count = 0;

	for (const char* c = str; c != 0; c++) {
		count++;
	}

	return count;
}


int find(char* src, const char* regex) { // looks for the first index of string regex in src and returns the index where the regex begins or -1 if there is no instance of regex
	int result = -1;
	int matchingCharacters = 0;
	const int targetMatches = len(regex);
	int i = 0; 
	for (char* c = src; *c > 0; (c++, i++)) {
		char charToMatch = *(regex + matchingCharacters); 
		if (*c == charToMatch) {
			matchingCharacters++;
		} else {
			matchingCharacters = 0;
		}
		
		if (matchingCharacters == targetMatches) {
			result = i - targetMatches + 1;
			break;
		}
	}
	
	return result;
}


char* substr(char* src, int begin, int end) {
	char* result = (char*)calloc(end - begin + 1, sizeof(char)); // + 1 to account for terminating 0 at the end of the string
	
	for (int i = begin; i < end; i++) {
		char c = *(src + i);
		*(result + (i - begin)) = c;
	}

	*(result + end) = 0; // string terminated with 0
	
	return result;
}

char* substrFrom(char* src, int begin) {
	return substr(src, begin, len(src) + 1);
}


