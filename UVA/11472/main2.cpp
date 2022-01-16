#include <bits/stdc++.h>
#define fast cin.tie(0),ios::sync_with_stdio(0),cout.tie();
#define all(a) a.begin(),a.end()

typedef long long ll;
typedef unsigned long long ull;

using namespace std;


const ll MOD = 1e9 + 7;

ll n,m;
ll dp[102][11][1 << 11];

ll solve(ll rem,ll current,ll mask){
    if(!rem)
        return (mask + 1) == (1 << n);
    
    ll &ret = dp[rem][current][mask];
    if(~ret)
        return ret;
    ret = 0;
    if(!~current){
        for(ll i = 1;i < n;i++)
            ret = (ret + solve(rem - 1,i,mask | (1 << i))) % MOD;
    }
    else{
        if(current)
            ret = (ret + solve(rem - 1,current - 1,mask | (1 << (current - 1)))) % MOD;
        if(n - 1 - current)
            ret = (ret + solve(rem - 1,current + 1,mask | (1 << (current + 1)))) % MOD;
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
        memset(dp,-1,sizeof dp);
        cin >> n >> m;
        ll sol = 0;
        for(ll i = 0;i<=m;i++)
            sol = (sol + solve(i,-1,0)) % MOD;
        cout << sol << endl;
    }
}

