#include <stdio.h>
#include <stdlib.h>
#include <string.h>
// all good dar as vrea sa te uiti si sa zici daca e ok cum ii structurat
// & poate niste sugestii daca ai:)) ca ii ciudat sa lucrez cu atatea cifre exacte

/*3.1.Using the structure type to store a date (year, month, day), write a program to display the number of the day in a year, and the number of days to the end of that year.
*/

typedef struct{
    int day;
    int month;
    int year;
}dmy;
dmy readDate(){
    dmy date;
    printf("The date introduced is:\n");
    printf("day: ");
    scanf("%d",&date.day);
    printf("month:");
    scanf("%d",&date.month);
    printf("year: ");
    scanf("%d",&date.year);
    return date;
}
int  monthLess8(dmy date) {
    int i;
    int z1=0;
        for(i=1;i<date.month;i++) {
                    if (i % 2)
                         z1 = z1 + 31;
                    else {
                        if (i > 2)
                            z1 = z1 + 30;
                    }
                    if(i==2){
                    if(date.year%4)
                        z1=z1+28;
                    else
                        z1=z1+29;
                    }
                }
         z1=z1+date.day;
    return z1;
    }
int year(int year,int z1){
    int z2;
    if(year%4)
        z2=365-z1;
    else
        z2=366-z1;
    return z2;
}
int monthMore8(dmy d){
    dmy max={31,7,d.year};
    int z1=monthLess8(max);
    for(int i=8;i<d.month;i++){

        if(i%2)
            z1=z1+30;
        else
            z1=z1+31;
    }
    z1=z1+d.day;
    return z1;
}
int main() {
    dmy d=readDate();
    int z1;//zile au trecut
    int z2; //zile au mai ramas
       if(d.month<=7){
           z1=monthLess8(d);
           z2=year(d.year,z1);
           printf("Au trecut %d zile de la inceputul anului si au mai ramas %d pana se termina anul.",z1,z2);
    }
       else{
           z1=monthMore8(d);
           z2=year(d.year,z1);
        printf("Au trecut %d zile de la inceputul anului an si au mai ramas %d pana se termina anul.",z1,z2);
    }
    return 0;
}
