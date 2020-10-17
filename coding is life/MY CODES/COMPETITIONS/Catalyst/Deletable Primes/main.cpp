#include <iostream>
int isPrime(int x){
    int d;
    if(x<2 || (x%2==0 && x!=2))
        return 0;
    for(d=3;d*d<x;d=d+2){
        if(x%d==0)
            return 0;
    }
    return 1;
}
int lenNumber(int x){
    int k=0;
    while(x){
        x=x/10;
        k++;
    }
    return k;
}
int deleteDigit(int x,int c){
    //c- the digit from the tail to the head
    int nr,k=0,p=1;
    while(x){
        k++;
        if(k!=c) {
            nr = nr + (x % 10) * p;
            p=p*10;
        }
        x=x/10;
    }
    return nr;
}
int verifyDeleteablePrime(int n){
    int ok=0,i,n1=n,k=lenNumber(n);
    while(k>9){
        k--;
        ok=0;
        for(i=0;i<=lenNumber(n) && ok==0;i++) {
            n1 = deleteDigit(n,i);
            if (isPrime(n1)) {
                ok = 1;
                n=n1;
            }
        }
        if(ok==0)
            return 0;
    }
    return 1;
}
int main() {
   int n;
   std::cout<<"Introduce the number: ";
   std::cin>>n;
   if(verifyDeleteablePrime(n))
       std::cout<<"The number is a deletable prime";
   else
       std::cout<<"The number isn't a deletable prime";
   return 0;
}
5
