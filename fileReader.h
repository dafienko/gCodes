#pragma once
#include <stdio.h>

typedef struct LINES {
	char** lines;
	int numLines;
} LINES;

LINES* getFileLines(FILE*);

