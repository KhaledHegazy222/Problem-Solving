
#include <bits/stdc++.h>
#define all(x) x.begin(),x.end()
using namespace std;


typedef unsigned long long ull;
typedef long long ll;
typedef vector<vector<int>> vvi;
typedef vector<int> vi;






int main(void){
   
    #ifdef offline_vs_code
        freopen("out.txt","w",stdout);
        freopen("in.txt","r",stdin);
    #endif 

    ll n;
    while(1){
        cin >> n;
        if(n < 0) return 0;


        if(n){
            cout << (n) *(n+1)/2 + 1 << endl;
        }
        else{
            cout << 1 << endl;
        }
    }



}   
