#include <iostream>

int isPrime(long long n){
    int d;
    if(n<1&& (n%2==0 && n!=2))
        return 0;
    for(d=3;d*d<n;d+=2){
        if(n%d==0)
            return 0;
    }
    return 1;
}
int main() {
    long long  n;
    std::cin>>n;
    std::cout << isPrime(n) << std::endl;
    return 0;
}