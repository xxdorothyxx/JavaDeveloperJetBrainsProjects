//
//  io.h
//  assignment7_chaining
//
//  Created by Sandor Doroteea on 5/20/20.
//  Copyright © 2020 Doroteea Sandor. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

static const int MAX_STRING_LENGTH = 64;

char * randString();

void writeToFile(int N);

char ** readFromFile(int N);

FILE * getFileForInt(int N);

void printContentToConsole(char ** contents, int N);
