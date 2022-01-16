#include <bits/stdc++.h>
#define fast cin.tie(0),ios::sync_with_stdio(0),cout.tie();
#define all(a) a.begin(),a.end()

typedef long long ll;
typedef unsigned long long ull;

using namespace std;

const ll N = 1e6 + 5;


ll dp[N];

ll div(ll n){

    ll &ret = dp[n];
    if(~ret)
        return ret;
    ret = 0;
    for(ll i = 1;i * i <= n;i++){
        if(n % i == 0)
            ret += (i != n / i) + 1;
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
    

    memset(dp,-1,sizeof dp);
    ll t;
    cin >> t;
    while(t--){
        ll a,b;
        cin >> a >> b;
        ll g = __gcd(a,b);
        cout << div(g) << endl;
    }
}


