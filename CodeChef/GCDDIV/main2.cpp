#include <bits/stdc++.h>
#define fast cin.tie(0),ios::sync_with_stdio(0),cout.tie();
#define all(a) a.begin(),a.end()

typedef long long ll;
typedef unsigned long long ull;

using namespace std;

ll factorize(ll n){
    ll ret = 0;
    for(ll i = 2;i * i <= n;i++){
        while(n % i == 0){
            ret = max(ret,i);
            n /= i;
        }
    }
    return max(ret,n);
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
        ll n,k;
        cin >> n >> k;
        ll g = 0;
        while(n--){
            ll x;
            cin >> x;
            g = __gcd(x,g);
        }

        ll res = factorize(g);
        if(res > k)
            cout << "NO\n";
        else
            cout << "YES\n";
        
    }    

}
//

