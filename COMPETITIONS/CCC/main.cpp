#include <iostream>
#include <fstream>
//#include <limits.h>
using namespace std;

ifstream in("in.txt");
ofstream of("out.txt");

struct powerr
{
    int value;
    int possibleP;
};

struct time
{
    int power;
    int start;
    int finish;
    int position;
    powerr P[100000];
};


int minIndex(powerr a[],int start, int end,int maxUsed,int array[])
{
    int min=-1;
    int j = start;
    for (int i = start; i <= end; i++)
    {
        if (a[i].possibleP != 0 && array[i]>0)
        {

            if (min == -1 || a[i].value < min)
            {
                min = a[i].value;
                j = i;
            }
        }

    }
    array[j]--;
    return j;
}

int main() {
    int maxNumber;
    int index;
    int min;
    int N;
    int i;
    int j;
    powerr a[100000];
    int maxPower;
    long maxElectricity;
    int array[100000];
    in >> maxPower;
    in >> maxElectricity;
    in>>maxNumber;
    in >> N;
    for (int i = 0; i < N; i++) {
        in >> a[i].value;
        a[i].possibleP = maxPower;
        array[i]=maxNumber;
    }
    int M;
    in >> M;
    struct time b[100000];
    of << M << "\n";
    for (int i = 1; i <= M; i++) {
        in >> b[i].position >> b[i].power >> b[i].start >> b[i].finish;
    }
    for (i = 1; i < M; i++) {
        for (j = 1 + i; j <= M; j++)
            if (b[i].finish - b[i].start + 1 > b[j].finish - b[j].start + 1) {
                struct time aux;
                aux = b[i];
                b[i] = b[j];
                b[j] = aux;
            }
    }
    for (i = 1; i <= M; i++) {
        b[i].P[0].possibleP = 0;
        b[i].P[0].value = 0;
        while (b[i].power != 0) {
            b[i].P[0].value++;
            b[i].P[b[i].P[0].value].value = minIndex(a, b[i].start, b[i].finish,maxNumber,array);
            if (a[b[i].P[b[i].P[0].value].value].possibleP >= b[i].power) {
                b[i].P[b[i].P[0].value].possibleP = b[i].power;
                a[b[i].P[b[i].P[0].value].value].possibleP -= b[i].power;
                b[i].power = 0;
            } else {
                b[i].P[b[i].P[0].value].possibleP = a[b[i].P[b[i].P[0].value].value].possibleP;
                b[i].power -= a[b[i].P[b[i].P[0].value].value].possibleP;
                a[b[i].P[b[i].P[0].value].value].possibleP = 0;
            }
        }
    }

    int l = 1;
    while (l <= M) {
        for (i = 1; i <= M; i++) {
            if (b[i].position == l) {
                of << l << " ";
                for (j = 1; j <= b[i].P[0].value; j++)
                    of << b[i].P[j].value << " " << b[i].P[j].possibleP << " ";
            }
        }
        l++;
        of << "\n";
    }
    of.close();
    in.close();
    return 0;
}