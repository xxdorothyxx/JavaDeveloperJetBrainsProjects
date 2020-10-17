#include <stdio.h>
#include <stdlib.h>

const int MAX_LENGTH = 200;

int main()
{
    FILE * f;

    f = fopen("example_file.txt","w");

    char * strbuf = (char*) malloc(sizeof(char)*MAX_LENGTH);

    while(fgets(strbuf, MAX_LENGTH, f) != NULL)
        puts(strbuf);

    fputs("powerverwhelming", f);

    fclose(f);

    return 0;
}