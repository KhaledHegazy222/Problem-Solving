#include <bits/stdc++.h>
#define fast cin.tie(0),ios::sync_with_stdio(0),cout.tie();
#define all(a) a.begin(),a.end()

typedef long long ll;
typedef unsigned long long ull;

using namespace std;

const ll N = 1e4 + 5;

vector<ll> fact(ll n){
    vector<ll>ret(N);
    for(ll i = 2;i * i <= n;i++){
        while(n % i == 0){
            n /= i;
            ret[i]++;
        }
    }
    ret[n]++;
    return ret;
}

ll solve(ll n,ll p){
    ll cnt = 0;
    for(ll i = p;i <= n;i *= p)
        cnt += n / i;
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

    ll cs = 1;
    ll t;
    cin >> t;
    while(t--){
        cout << "Case " << cs++ << ":\n";
        ll m,n;
        cin >> m >> n;
        ll sol = 1e9;
        auto ret = fact(m);
        // for(ll i = 0;i<=m;i++)
        //     if(ret[i])
        //         cout << i << " " << ret[i] << endl;
        for(ll i = 2;i <= m;i++){
            if(ret[i])
                sol = min(sol,solve(n,i) / ret[i]);
        }
        if(!sol || sol > 1e8)
            cout << "Impossible to divide\n";
        else
            cout << sol << endl;
    }

    
    


}


