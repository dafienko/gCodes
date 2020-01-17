#include <stdlib.h>
#include <stdio.h>

#include "fileReader.h"

#define MAX_LINES 9999

<<<<<<< HEAD
int find(const char* src, const char* regex) {
	int result = -1;
	char* srcPtr = src;	

	for (char c = *src; c != 0; c++) {
		printf("%c", *c);
	}

	return result;
}

=======
>>>>>>> 8056506af0869378291a86fab8eeb4b0a433e00a
int main() {
	char* fileName = "words.txt";
	FILE* file = fopen(fileName, "r");
	if (file == NULL) {
		printf("failed to load file\n");
		return -1;
	}	
	
	LINES* fileInfo = getFileLines(file);	
	char** lines = fileInfo->lines;
	int numLines = fileInfo->numLines;

	for (int i = 0; i < numLines; i++) {
		char* ptr = *(lines + i);
<<<<<<< HEAD
		find(ptr, "bruh");
		char* prefix = (char*)calloc(5, sizeof(char));
		sprintf(prefix, "%c%c%c\n", *(ptr), *(ptr + 1), *(ptr + 2));
		printf(prefix);
	}
	
=======
		printf(ptr);
	}
	
	
>>>>>>> 8056506af0869378291a86fab8eeb4b0a433e00a
	for (int i = 0; i < numLines; i++) {
		char* ptr = *(lines + i);
		free(ptr);
	}
<<<<<<< HEAD

	free(fileInfo);

	return 0;
}

=======
	free(fileInfo);


	return 0;
}
>>>>>>> 8056506af0869378291a86fab8eeb4b0a433e00a
