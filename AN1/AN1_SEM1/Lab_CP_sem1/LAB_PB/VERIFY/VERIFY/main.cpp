#include <iostream>

int main() {
   int n,a[100][100],i,j;
   std::cout<<"Introduce the number: ";
   std::cin>>n;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            std::cin>>a[i][j];
        }
    }
    for(i=0;i<n/2;i++){
        for(j=0;j<n/2;j++){
            int aux=a[i][j];
            a[i][j]=a[j][n-i-1];
            a[j][n-i-1]=aux;
            
            
        }
    }
    for(i=0;i<n;i++)
        for(j=0;j<n;j++)
            std::cout<<a[i][j];
   return 0;
}
