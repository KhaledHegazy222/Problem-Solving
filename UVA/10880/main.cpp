#include <bits/stdc++.h>
#define fast cin.tie(0),ios::sync_with_stdio(0),cout.tie();
#define all(a) a.begin(),a.end()

typedef long long ll;
typedef unsigned long long ull;

using namespace std;

vector<ll> fact(ll n){
    vector<ll>ret;
    for(ll i = 1;i * i <= n;i++){
        if(n % i == 0){
            ret.push_back(i);
            if(n / i != i)
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

    ll cs = 1;
    ll t;
    cin >> t;
    while(t--){
        cout << "Case #" << cs++ << ":"; 
        ll c,r;
        cin >> c >> r;
        if(r == c){
            cout << " 0\n";
            continue;
        }


        auto res = fact(c - r);
        sort(all(res));
        for(ll i = 0;i < res.size();i++){
            if(res[i] > r)
                cout << " " << res[i];
        }
        cout << endl;
    }
    

}


