#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//all good dar daca zic ca vreau n siruri pot introduce numai n-1 struri si nush de ce

char **readSt(int n){
    char **a=(char**)malloc(n*sizeof(char*));
    int i;
    for(i=0;i<n;i++){
        a[i]=(char*)malloc(100*sizeof(char));
    }
    printf("Introduce the strings:\n");
    for(i=0;i<n;i++){
        gets(a[i]);
    }
     return a;
}
char *longestString(int n,char **s,char *s1) {
    int max=0;
    for (int i = 0; i<n ; i++) {
        if (strlen(s[i]) > max) {
            max = strlen(s[i]);
            strcpy(s1, s[i]);
        }
    }
    return s1;
}
char *biggestString(int n,char **s,char*s2){
    int i;
    strcpy(s2,"");
    for(i=0;i<n;i++) {
        if (strcmp(s[i], s2) > 0) {
            strcpy(s2, s[i]);
        }
    }
    return s2;
}
 int main() {
     int n;
     printf("Introduceti numarul de siruri: \n");
     scanf("%d",&n);
     char **s;
     s=readSt(n);
     char *s1,*s2;
     s1=(char*)malloc(100*sizeof(char));
     s2=(char*)malloc(100*sizeof(char));
    printf("Sirul cu cele mai multe caractere este:\n");
    puts(longestString(n,s,s1));
    printf("Sirul cel mai mare alfabnumeric este:\n");
    puts(biggestString(n,s,s2));
    return 0;
}
