#include <bits/stdc++.h>
#define fast cin.tie(0),ios::sync_with_stdio(0),cout.tie();
#define all(a) a.begin(),a.end()

typedef long long ll;
typedef unsigned long long ull;

using namespace std;


const ll MOD = 1e9 + 7;

const ll N = 1e6 + 5;
ll fact[N],factInv[N];

ll power(ll b,ll p){
    ll ret = 1;
    while(p){
        if(p & 1)
            ret = (1ll * ret * b) % MOD;
        b = (1ll * b * b) % MOD;
        p >>= 1;
    }
    return ret;
}



void init(){
    fact[0] = 1;
    factInv[0] = 1;
    for(ll i = 1;i < N;i++){
        fact[i] = (1ll * fact[i - 1] * i) % MOD;
        factInv[i] = (1ll * factInv[i - 1] * power(i,MOD - 2)) % MOD;
    }
}


ll nCr(ll n,ll r){
    return ( 1ll * ((1ll * fact[n] * factInv[r]) % MOD) * factInv[n - r]) % MOD;
}



ll excellent(ll n,ll a,ll b){
    while(n){
        if( n % 10 != a && n % 10 != b)
            return 0;
        n /= 10;
    }
    return 1;
}

signed main(void){

    #ifdef Khaled
        freopen("in.txt","r",stdin);
        //freopen("out.txt","w",stdout);
    #endif
    #ifndef Khaled
        #define endl '\n'
        fast;
    #endif
    
    init();



    ll a,b;
    cin >> a >> b;
    ll n;
    cin >> n;
    ll res = 0;
    for(ll i = 0;i <= n;i++){
        if(excellent(a * i + b * (n - i),a,b)){
            res = (0ll + res + nCr(n,i)) % MOD;
        }
    }


    cout << res << endl;


}


