#include "fileReader.h"
#include <stdlib.h>
#include <stdio.h>

#define MAX_LINES 9999

int min(int a, int b) {
	return ((a > b) ? a : b);
}

int max(int a, int b) {
	return ((a < b) ? a : b);
}


LINES* getFileLines(FILE* file) {	
	LINES* result = malloc(sizeof(LINES));

	int bufferSize = 10;
	int lineLength = 1;
	char* line = (char*)calloc(bufferSize, sizeof(char));
	char** lines = calloc(MAX_LINES, sizeof(char*)); 
	int numLines = 0;
	char c = getc(file);

	do {
//		printf("%c", c);
		if (c != EOF && c != '\n') {
			lineLength++;
			if (lineLength >= bufferSize - 1) {
				bufferSize *= 2;
				char* newLine = realloc(line, bufferSize * sizeof(char));
				if (newLine) {
					line = newLine;
				} else {
					free(line);
					break;	
				}
			}
			
			sprintf(line, "%s%c", line, c);
		} else if (c == '\n') {
			sprintf(line, "%s%c", line, '\n');
			*(lines + numLines) = line;	
			lines[min(numLines, MAX_LINES)] = line;	
			bufferSize = 10;
			line = (char*)calloc(bufferSize, sizeof(char));
			lineLength = 1;
			numLines++;
		}	
		
		c = getc(file);
	} while (c != EOF);
	
	result->lines = lines;
	result->numLines = numLines;
	
	return result;
}
