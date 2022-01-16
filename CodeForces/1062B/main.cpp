#include <bits/stdc++.h>
#define fast cin.tie(0),ios::sync_with_stdio(0),cout.tie();
#define all(a) a.begin(),a.end()

typedef long long ll;
typedef unsigned long long ull;

using namespace std;


map<ll,ll> factorize(ll n){
    map<ll,ll>ret;

    for(ll i = 2;i * i <= n;i++){
        while(n % i == 0){
            ret[i]++;
            n /= i;
        }
    }

    if(n != 1)
        ret[n]++;
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

    ll n;
    cin >> n;
    // if(n == 1)
    //     return cout << 0 << endl,0;
    auto res = factorize(n);

    ll ans = 1;
    ll mx = 0;
    ll add = 0;
    vector<ll>v = {1};
    for(ll i = 0;i < 20;i++)
        v.push_back(v.back() << 1);
    for(auto elem :res){
        ans *= elem.first;
        ll z = lower_bound(all(v),elem.second) - v.begin();
        mx = max(mx,z);
    }
    for(auto elem : res)
        add |= elem.second != v[mx];
    cout << ans << " " << mx + add << endl;




}


