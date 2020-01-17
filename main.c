#include <stdlib.h>
#include <stdio.h>

#include "fileReader.h"
#include "stringUtil.h"

#define MAX_LINES 9999


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
		char* line = *(lines + i);
		int colonIndex = find(line, ":"); 
		if (colonIndex > 0) { // there is a colon in the string
			
		}
	}
	
	
	for (int i = 0; i < numLines; i++) {
		char* ptr = *(lines + i);
		free(ptr);
	}

	free(fileInfo);



	return 0;
}
