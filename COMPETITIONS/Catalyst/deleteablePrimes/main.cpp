#include <iostream>
int nr;
using namespace std;

long long taie (long long n, int i)
{
    long long j, a, b, c=1;
    for(j=i;j>0;j--)
        c = c*10;
    a = n / c;
    b = n % (c/10);
    a = a * (c/10) + b;
    return a;
}

int prim(long long a)
{
    if(a==2)
        return 1;
    int i;
    for(i=2;i<=a/2;i++)
        if(a%i==0)
            return 0;
    return 1;
}

int sub(long long n)
{
    int s=0, i, a;
    if(n<10)
    {
        if(prim(n)==1)
            nr++;
        return 0;
    }
    for(a=n;a>0;a=a/10)
        s++;
    for(i=1;i<=s;i++)
    {
        if(prim(taie(n, i))==1)
            sub(taie(n, i));
    }
}
int main()
{
    long long n;
    cin >> n;
    sub(n);
    cout << nr;
}
