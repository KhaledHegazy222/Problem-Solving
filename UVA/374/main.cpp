

#include <bits/stdc++.h>
#define all(x) x.begin(),x.end()


typedef unsigned long long ull;
typedef long long ll;

using namespace std;

int p_mod(int base,int power,int mod){
    if(power == 0) return 1;
    int ret = 1;
    while(power){
        if(power & 1)
            ret = (1ll * ret * base)%mod;
        base = (1ll * base * base ) %mod;
        power /= 2;
    }
    return ret;
}



int main(void){
   
    #ifdef offline_vs_code
        freopen("out.txt","w",stdout);
        freopen("in.txt","r",stdin);
    #endif 
    int base,power,mod;
    while(cin >> base >> power >> mod){
        cout << p_mod(base,power,mod) << '\n';
    }
}   


