#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//da bine dar nush daca arata bine codul
void verifySubstring(char *s1,char *s2){
if(strstr(s1,s2))
printf("\nPozitia de la care incepe sirule este: %lu\n",strlen(s1)-strlen(strstr(s1,s2)));
else
printf("Subsirul nu este inclus in sir\n");
}
int main()
{
char *s1,*s2;
s1=(char*)malloc(100*sizeof(char));
s2=(char*)malloc(100*sizeof(char));
printf("Sirul dat este:\n");
gets(s1);
printf("Subsirul dat este:\n");
gets(s2);
verifySubstring(s1, s2);
}
