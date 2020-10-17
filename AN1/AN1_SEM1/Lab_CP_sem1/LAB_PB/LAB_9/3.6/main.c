#include <stdio.h>
#include <string.h>
#include <stdlib.h>
// se poate face si cu astea doua funcii...ii ok sau trebuie sa o fac cu cealalta metoda too?
int main() {
    char *s;
    int number;
    s=(char*)malloc(100*sizeof(char));
    printf("Sirul de caractere dat este:\n");
    scanf("%s",s);
    sscanf(s,"%d",&number);
    printf("%d",number);
    printf("\nNow let's change it back into a string of characters:\n");
    sprintf(s,"%d",number);
    printf("%s",s);
    return 0;
}
