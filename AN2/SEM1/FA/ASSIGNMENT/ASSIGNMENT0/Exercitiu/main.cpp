#include <iostream>
#include <fstream>
#include <cmath>
using namespace std;

ofstream g("out.csv");

int main() {
    int n,nr;
    g<<"n,100*log(n),10*n,0.5*n*n"<<endl;
    for(n=100;n<=10000;n+=100){
        g<<n<<",";
        nr=log(n);
        g<<100*nr<<",";
        g<<10*n<<",";
        double nr2=pow(n,2)*0.5;
        g<<nr2<<endl;
    }
    return 0;
}
