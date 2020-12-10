#include <iostream>
#include <cstring>

using namespace std;

int main() {
    int T,contor=0;
    cin>>T;
    char a[100];
    for(int k=1;k<=T;k++){
        cin>>a;
        contor = 0;
        char* p = strstr(a,"KICK");
        while(p){
        char* m =strstr(p,"START");
        while(m){
            contor++;
            m=strstr(m,"START");
        }
        p=strstr(p,"START");
        }

        cout<<"Case #"<<k<<": "<<contor;
    }
    return 0;
}
