#include <bits/stdc++.h>
#define fast cin.tie(0),ios::sync_with_stdio(0),cout.tie();
#define all(a) a.begin(),a.end()

typedef long long ll;
typedef unsigned long long ull;

using namespace std;

const int MOD = 1e9 + 7;


signed main(void){

    #ifdef Khaled
        freopen("in.txt","r",stdin);
        //freopen("out.txt","w",stdout);
    #endif
    #ifndef Khaled
        #define endl '\n'
        fast;
    #endif
    
    ll n;
    cin >> n;
    vector<ll>v(n + 1);
    for(ll i = 0;i<n;i++)
        cin >> v[i];
    sort(all(v));
    ll res = 1;
    for(ll i = n;i > 0;i--)
        res = (res * (v[i] - v[i - 1] + 1)) % MOD;
    cout << res << endl;

}


