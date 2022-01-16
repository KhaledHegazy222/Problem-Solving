#include <bits/stdc++.h>
#define fast cin.tie(0),ios::sync_with_stdio(0),cout.tie();
#define all(a) a.begin(),a.end()

typedef long long ll;
typedef unsigned long long ull;

using namespace std;


ll div(ll n){
    ll cnt = 0;
    for(ll i = 1;i * i <= n;i++){
        if(n % i == 0)
            cnt += (i != n / i) + 1;
    }
    return cnt;
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
        ll l,r;
        cin >> l >> r;
        ll mx = -1,sol = -1;
        for(ll i = l;i <= r;i++){
            ll ret = div(i);
            if(ret > mx)
                mx = ret,sol = i;
        }
        cout << "Between " << l << " and " << r << ", " << sol << " has a maximum of " << mx << " divisors.\n";
    }
}

//
