#include <bits/stdc++.h>
#define fast cin.tie(0),ios::sync_with_stdio(0),cout.tie();
#define all(a) a.begin(),a.end()

typedef long long ll;
typedef unsigned long long ull;

using namespace std;

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
        ll n,q;
        cin >> n >> q;
        vector<ll>v(n);
        for(auto &elem : v)
            cin >> elem;
        ll prefGCD[n + 2] = {0};
        ll suffGCD[n + 2] = {0};
        for(ll i = 1;i <= n;i++){
            prefGCD[i] = __gcd(prefGCD[i - 1],v[i - 1]);
        }
        for(ll i = n;i > 0;i--){
            suffGCD[i] = __gcd(suffGCD[i + 1],v[i - 1]);
        }
        while(q--){
            ll l,r;
            cin >> l >> r;
            cout << __gcd(prefGCD[l - 1],suffGCD[r + 1]) << endl;
        }
    }    

}


