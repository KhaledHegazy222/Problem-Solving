#include <bits/stdc++.h>
#ifndef Khaled
    #define endl '\n'
#endif
#define fast cin.tie(0),ios::sync_with_stdio(0),cout.tie();
#define all(a) a.begin(),a.end()

typedef long long ll;
typedef unsigned long long ull;

using namespace std;


ll cnt(ll x,ll p){
    return x / p;
}

ll cntRange(ll l,ll r,ll p){
    return cnt(r,p) - cnt(l - 1,p);
}



signed main(void){

    #ifdef Khaled
        freopen("in.txt","r",stdin);
        //freopen("out.txt","w",stdout);
    #endif
    fast;


    ll n,p;
    cin >> n >> p;
    vector<pair<ll,ll>>v(n);
    for(ll i = 0;i<n;i++){
        cin >> v[i].first >> v[i].second;
    }
    double res = 0;
    for(ll i = 0;i<n;i++){
        ll j = (i + 1) % n;
        ll npi = cntRange(v[i].first,v[i].second,p);
        ll npj = cntRange(v[j].first,v[j].second,p);
        ll pairs = npi * (v[j].second - v[j].first + 1) + npj * (v[i].second - v[i].first + 1) - npj * npi;
        res += ((pairs * 1.0) / ((v[j].second - v[j].first + 1) * (v[i].second - v[i].first + 1))) * 2000;
    }
    cout << fixed << setprecision(6) << res << endl;



}



