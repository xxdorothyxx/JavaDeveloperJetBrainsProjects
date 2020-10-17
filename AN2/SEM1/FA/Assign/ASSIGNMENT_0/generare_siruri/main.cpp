/*Generare cazuri de testare
 Pași:
 Citește n, min și max de la tastatură
 Generează un șir aleatoriu de n elemente cu valori cuprinse intre min și max
 Șirul trebuie să fie diferit la fiecare rulare a programului
 Adaugă șirul în fișierul output.txt*/

#include <iostream>
#include <fstream>
#include <math.h>
#include <time.h>
using namespace std;
//ifstream f("in.txt");
ofstream g("out.txt");
int main() {
    int n,min,max,nr;
    time_t secondsFromEpoch=time(NULL);
    srand(secondsFromEpoch);
    cin>>n>>min>>max;
   // std :: cout<<min<<" "<<max;
    for(int i=0;i<n;i++){

      nr= rand() % max + min;
      g<<nr<<endl;
    }
    return 0;
}
