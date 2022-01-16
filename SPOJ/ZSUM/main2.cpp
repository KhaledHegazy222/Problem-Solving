#include <bits/stdc++.h>
#define fast cin.tie(0),ios::sync_with_stdio(0),cout.tie();
#define all(a) a.begin(),a.end()

typedef long long ll;
typedef unsigned long long ull;

using namespace std;


const ll MOD = 10000007;

ll power(ll b,ll p){
    ll ret = 1;
    while(p){
        if(p & 1){
            ret = (1ll * ret * b) % MOD;
        }
        b = (1ll * b * b) % MOD;
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
    
    ll n,k;
    while(cin >> n >> k,n,k){

        if(n < 100){
            ll Z = 0;
            for(ll i = 1;i <= n;i++)
                Z += power(i,k);
            for(ll i = 1;i <= n;i++)
                Z += power(i,i);
            
            for(ll i = 1;i <= n - 1;i++)
                Z += power(i,k);
            for(ll i = 1;i <= n - 1;i++)
                Z += power(i,i);

            for(ll i = 1;i <= n - 2;i++)
                Z -= 2 * power(i,k);
            for(ll i = 1;i <= n - 2;i++)
                Z -= 2 * power(i,i);


            cout << Z % MOD << endl;

            

            continue;
        }

        cout << (0ll + power(n,k) + 2 * power(n - 1,k) + power(n,n) + 2 * power(n-1,n-1)) % MOD << endl;
    }
}


