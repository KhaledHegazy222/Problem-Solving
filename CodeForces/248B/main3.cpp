
#include <bits/stdc++.h>
 
#define infinity 100000000
#define longlong ll
#define unsignedlonglong ull
#define all(x) x.begin(),x.end()
#define rep(i,b,e)   for(int i = b;i<e;i++)
 
 
using namespace std;
 
 
 
 
 
 
 
int main(void){
    #ifdef offline_vs_code
        string wait;
    #endif
 
 
    int n;
    cin >> n;
    if(n < 3){
        cout << -1 << endl;
    }
    else if(n == 3){
        cout << 210 << endl;
    }
    else if(n == 4){
        cout << 1050 << endl;
    }
    else{
        int mod = 50;
        cout << 1;
        for(int i = 0;i<n-4;i++){
            cout << 0;
            mod *= 10;
            mod %= 210;
        }
        if(mod < 10){
            cout << "00" << mod << endl;
        }
        else if(mod < 100){
            cout << 0 << mod << endl;
        }
        else{
            cout << mod << endl;
        }
    }
 
 
 
 
 
    #ifdef offline_vs_code
        getline(cin,wait);
        getline(cin,wait);
    #endif 
 
 
}
 
 
