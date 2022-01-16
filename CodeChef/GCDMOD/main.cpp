#include <bits/stdc++.h>
#define fast cin.tie(0),ios::sync_with_stdio(0),cout.tie();
#define all(a) a.begin(),a.end()

typedef long long ll;
typedef unsigned long long ull;

using namespace std;

ll MOD;

ll safeMul(ll b,ll p){

    ll ret = 0;
    while(p){
        if(p & 1){
            ret += b;
            ret %= MOD;
        }

        b += b;
        b %= MOD;
        p >>= 1;
    }
    return ret;

}


ll power(ll b,ll p){

    ll ret = 1;
    while(p){
        if(p & 1){
            ret = safeMul(ret,b);
        }

        b = safeMul(b,b);
        p >>= 1;
    }
    return ret;

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


    ll t;
    cin >> t;
    while(t--){
        ll a,b,n;
        cin >> a >> b >> n;
        MOD = abs(a - b);
        if(!MOD){
            MOD = 1e9 + 7;
            cout << (power(a,n) + power(b,n)) % MOD << endl;
            continue;
        }

        ll res = (power(a,n) + power(b,n)) % MOD;
        cout << __gcd(res,MOD) % ((ll) 1e9 + 7) << endl;
    }
    

}


