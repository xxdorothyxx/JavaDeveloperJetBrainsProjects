#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
int main() {
    char *a;
    char *b;
    char c='U';
    a=(char *)malloc(8);
    strcpy(a+1,"abcDEFg");
    printf("1: %c\n",a[0]);
    *a='A';
    printf("2: %s\n",a);
    a[4]=c;
    b=&c;
    printf("3: %c\n",*b);
    b=&(a[3]);
    toupper(a[1]);
    toupper(a[2]);
    printf("4: %s\n",a);
    return 0;
}