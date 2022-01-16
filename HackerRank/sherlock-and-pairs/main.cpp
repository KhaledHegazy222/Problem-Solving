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
    return (1ll * ((1ll * fact[n] * factInv[n - r]) % MOD) * factInv[r] ) % MOD;
}
 
ll nPr(ll n,ll r){
    return (1ll * fact[n] * factInv[n - r]) % MOD;
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
    ll t;
    cin >> t;
    while(t--){
        ll n;
        cin >> n;
        map<ll,ll>mp;
        while(n--){
            ll x;
            cin >> x;
            mp[x]++;
        }
        ll res = 0;
        for(auto elem : mp){
            res += elem.second * (elem.second - 1);
        }
        cout << res << endl;
    }

}


