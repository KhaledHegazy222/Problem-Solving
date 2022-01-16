
#include <bits/stdc++.h>
#define all(x) x.begin(),x.end()
using namespace std;


typedef unsigned long long ull;
typedef long long ll;
typedef vector<vector<int>> vvi;
typedef vector<int> vi;
typedef vector<vector<ll>> vvll;
typedef vector<ll> vll;


const int MOD = 10000007;


int power_mod(int base,int power){
    int ret = 1;
    while(power > 0){
        if(power & 1)
            ret = (1ll * ret * base) % MOD;
        base = (1ll * base * base) % MOD;
        power >>= 1;
    }
    return ret;
}




int main(void){
   
    #ifdef offline_vs_code
        freopen("out.txt","w",stdout);
        freopen("in.txt","r",stdin);
    #endif 


    int n,k;
   

    while(1){
        cin >> n >> k;
        if(!n && !k) return 0;
        cout << (0ll + power_mod(n,n) + power_mod(n,k) + 2* power_mod(n-1,k) + 2 * power_mod(n-1,n-1)) %MOD << '\n';
    }

}   