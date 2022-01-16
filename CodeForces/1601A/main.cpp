#include <bits/stdc++.h>
#define fast cin.tie(0),ios::sync_with_stdio(0),cout.tie();
#define all(a) a.begin(),a.end()

typedef long long ll;
typedef unsigned long long ull;

using namespace std;



vector<ll> div(ll n){
    vector<ll>ret;
    for(ll i = 1;i * i <= n;i++){
        if(n % i == 0){
            ret.push_back(i);
            if(i != n / i)
                ret.push_back(n / i);
        }
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
        ll n;
        cin >> n;
        vector<ll>pq;
        for(ll i = 0;i<n;i++){
            ll x;
            cin >> x;
            pq.push_back(x);
        }
        vector<ll>res;
        if(!accumulate(all(pq),0ll)){
            res.resize(n);
            iota(all(res),1);
            for(auto elem : res)
                cout << elem << " ";
            cout << endl;
            continue;
        }
        for(ll i = 0;i < 31;i++){
            ll cnt = 0;
            for(ll j = 0;j < n;j++){
                cnt += (pq[j] >> i) & 1;
            }
            if(cnt)
                res.push_back(cnt);
        }
        ll g = 0;
        for(auto elem : res)
            g = __gcd(g,elem);

        res = div(g);
        sort(all(res));
        for(auto elem : res)
            cout << elem << " ";
        cout << endl;
        
    }
}


