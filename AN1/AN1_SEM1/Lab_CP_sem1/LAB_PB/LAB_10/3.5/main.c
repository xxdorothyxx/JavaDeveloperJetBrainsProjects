#include <stdio.h>
#include <stdlib.h>
#include <math.h>

/* 3.5.Construct a new type, rational type, as a structure composed of a numerator (integer)
 and a denominator (integer), used to represent fractions.Write functions to perform
 the operations: simplification, addition, subtraction, division,power for this type.*/

typedef struct{
    int num;
    int denom;
}rational;
rational readNumber(){
    rational n;
    printf("The numerator of the given number is:\n");
    scanf("%d",&n.num);
    printf("The denominator of the given number is:\n");
    scanf("%d",&n.denom);
    return n;
}
int cmmdc(int a,int b){
    int c;
    while(b){
        c=a%b;
        a=b;
        b=c;
    }
    c=a;
    return c;
}
rational simplification(rational n){
    int c=cmmdc(n.denom,n.num);
    n.denom=n.denom/c;
    n.num=n.num/c;
    return n;
}

rational addition(rational a,rational b){
    rational c;
    c.denom=a.denom*b.denom;
    c.num=a.num*b.denom+b.num*a.denom;
    c=simplification(c);
    return c;
}
rational substraction(rational a,rational b){
    rational c;
    c.denom=a.denom*b.denom;
    c.num=a.num*b.denom-b.num*a.denom;
    c=simplification(c);
    return c;
}
rational divide(rational a,rational b){
    rational c;
    c.num=a.num*b.denom;
    c.denom=a.denom*b.num;
    c=simplification(c);
    return c;
}
rational power(rational a,int n){
    rational c;
    c.num=pow(a.num,n);
    c.denom=pow(a.denom,n);
    return c;
}
int main() {
    rational number1=readNumber();
    printf("The first number is %d/%d\n",number1.num,number1.denom);
    rational s=simplification(number1);
    printf("After the simplification,the number is :%d/%d \n",s.num,s.denom);
    rational number2=readNumber();
    printf("The second number is %d/%d\n",number2.num,number2.denom);
    rational add=addition(number1,number2);
    printf("If we add number1 and number2 we obtain: %d/%d \n",add.num,add.denom);
    rational sub=substraction(number1,number2);
    printf("The substraction between number1 and number2 is: %d/%d \n",sub.num,sub.denom);
    rational div=divide(number1,number2);
    printf("If we divide number1 with number2 we obtain: %d/%d \n",div.num,div.denom);
    printf("The power we want to apply is : \n");
    int n;
    scanf("%d",&n);
    rational pow=power(number1,n);
    printf("The number powered is: %d/%d",pow.num,pow.denom);
    return 0;
}