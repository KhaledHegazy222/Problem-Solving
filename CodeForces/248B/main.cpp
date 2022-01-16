
#include <bits/stdc++.h>
 
 
 
using namespace std;
 
 
 
 
 
 
 
int main(void){

 

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
 
 
 
 
}