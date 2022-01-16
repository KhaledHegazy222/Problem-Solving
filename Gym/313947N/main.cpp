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
        ll n,m,t;
        cin >> n >> m >> t;
        vector<pair<ll,ll>>v(m);
        for(auto &elem : v)
            cin >> elem.first >> elem.second;
        sort(all(v));
        v.push_back({t,t});
        ll valid = 1;
        ll last = n - v.front().first;
        for(ll i = 0;i<m;i++){
            if(last <= 0)
                valid = 0;
            last = min(n,last + (v[i].second - v[i].first));

            last -= v[i + 1].first - v[i].second;
            if(last <= 0)
                valid = 0;
        }
        cout << (valid ? "YES\n" : "NO\n");

    }    

}


