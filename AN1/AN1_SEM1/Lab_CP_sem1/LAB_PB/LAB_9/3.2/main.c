//
//  main.c
//  untitled
//
//  Created by Sandor Doroteea on 11/26/19.
//  Copyright © 2019 Doroteea Sandor. All rights reserved.
//

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
// it works
void substring(int i,int n,char *s,char *s1)
{
    strcpy(s1,s+i);
    *(s1+n)='\0';
}
int main(int argc, const char * argv[]) {
    char *s,*s1;
    int i,n;
    printf("Subsirul incepe de la poz:\n");
    scanf("%d",&i);
    printf("Subsirul are un nr de carac egal cu:\n");
    scanf("%d",&n);
    s=(char*)malloc(100*sizeof(char));
    printf("Sirul introdus este:\n");
    getchar();
    gets(s);
    s1=(char*)malloc(100*sizeof(char));
    substring(i,n,s,s1);
    printf("Subsirul cerut este:\n");
    puts(s1);
}


