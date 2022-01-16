
#include <bits/stdc++.h>
#define all(x) x.begin(),x.end()
typedef unsigned long long ull;
typedef long long ll;

using namespace std;


const int MOD = 1e9 + 7;


int p_mod(int base,ll power, int mod){
    if(power == 0) return 1;
    int sqt = p_mod(base,power/2,mod);
    sqt = (1ll * sqt * sqt) % mod;
    if(power & 1) sqt = (1ll * sqt * base ) % mod;
    return sqt;
}


int main(void){
   
    #ifdef offline_vs_code
        freopen("out.txt","w",stdout);
        freopen("in.txt","r",stdin);
    #endif 


    int t;
    cin >> t;
    while(t--){
        int base;
        ll power;
        cin >> base >> power;
        cout << p_mod(base,power,10) << '\n';
    }
}   


