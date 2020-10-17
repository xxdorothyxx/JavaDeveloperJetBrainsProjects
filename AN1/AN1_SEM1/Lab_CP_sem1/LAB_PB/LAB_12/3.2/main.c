#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//3.2
//recursive
int HermitePoly(int n){
    if(n==0)
         return 1;
    else
        if(n==1)
            return 2;
    else
         return 2*n*HermitePoly(n-1)-2*(n-1)*HermitePoly(n-2);
}
//nonrecursive
int HermitePolyNon(int n){
    int a=1,b=2,c;
    if(n==0){
        return a;}
    else
        if(n==1){
            return b;}
    else{
        for(int i=2;i<=n;i++){
            c=2*i*b-2*(i-1)*a;
            a=b;
            b=c;
        }
    }
    return c;
}
int main() {
    int n,i;
    printf("The degree of the polynomial is:\n");
    scanf("%d",&n);
    if(n<2){
        printf("Error,please introduce a value grater or equal to 2 ");
        return 0;}
    printf("Enter rec or nonrec as the way you want your pol. to be calculated: ");
    char a[100];
    scanf("%s",a);
    printf("H(x)=");
    if(strcmp(a,"rec")==0) {
        for (i = 0; i <= n; i++) {
            printf("%d*x^%d", HermitePoly(i), i);
            if (i < n)
                printf("+");
        }
    }
    else{
        for(i=0;i<=n;i++){
            printf("%d*x^%d",HermitePolyNon(i),i);
            if(i<n)
                printf("+");
        }
    }
    return 0;
}