//
//  main.c
//  assignment7_chaining
//
//  Created by Sandor Doroteea on 5/20/20.
//  Copyright © 2020 Doroteea Sandor. All rights reserved.
//
#include "io.h"
#include "files.h"

int main()
{
    int N = _100;
    
    char ** content = readFromFile(N);
    printContentToConsole(content,N);

    return 0;
}
