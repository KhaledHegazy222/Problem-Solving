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
        vector<ll>v(n),com(n + 1);
        for(ll i = 0;i < n;i++){
            cin >> v[i];
            v[i] = (v[i] % 2) == 0;
            com[i + 1] = com[i] + v[i];
        }
        while(q--){
            ll l,r;
            cin >> l >> r;
            ll ev = com[r] - com[l - 1];
            ll odd = r - l + 1 - ev;
            ll ans = (ev) * (ev - 1) * (ev - 2) / 6 + ev * (odd) * (odd - 1) / 2;
            cout << ans << endl;


        }
    }    

}


