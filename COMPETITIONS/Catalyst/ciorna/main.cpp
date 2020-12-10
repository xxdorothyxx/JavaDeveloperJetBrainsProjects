#include<stdio.h>
#include<string.h>
#include<cstdlib>
int main()
{
    char *s,*s1;
    int i,n;
    printf("Pozitia de la care porneste subsirul este: ");
    scanf("%d\n",&i);
    printf("Subsirul are nr. de carac. egal cu: ");
    scanf("%d\n",&n);
    s=(char*)malloc(100* sizeof(char));
    s1=(char*)malloc(100* sizeof(char));
    gets(s);
    strcpy(s1,s+i);
    *(s1+n)='\0';
    puts(s1);
    return 0;
}