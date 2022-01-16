#include <bits/stdc++.h>
#ifndef Khaled
    #define endl '\n'
#endif
#define all(a) a.begin(),a.end()
#define fast cin.tie(0),ios::sync_with_stdio(0),cout.tie(0)

typedef long long ll;
typedef unsigned long long ull;

using namespace std;

const ll N = 1e2 + 5;
ll cnt[N],price[N],n;

ll dp[N][N];


ll solve(ll idx,ll last,ll sum){
    if(idx == n){
        return (sum ? INT_MAX : 0);
    }
    ll &ret = dp[idx][last];
    if(~ret)
        return ret;

    ll ch1 = (sum + cnt[idx] + 10) * price[idx] + solve(idx + 1,idx + 1,0);
    ll ch2 = solve(idx + 1,last,sum + cnt[idx]);

    return ret = min(ch1,ch2);

}




signed main(void){

    #ifdef Khaled
        freopen("in.txt","r",stdin);
        //freopen("out.txt","w",stdout);
    #endif
    fast;

    ll t;
    cin >> t;
    while(t--){
        memset(dp,-1,sizeof dp);
        cin >> n;
        for(ll i = 0;i<n;i++)
            cin >> cnt[i] >> price[i];
        cout << solve(0,0,0) << endl;
    }

}