#include <bits/stdc++.h>
#ifndef Khaled
    #define endl '\n'
#endif
#define all(a) a.begin(),a.end()
#define fast cin.tie(0),ios::sync_with_stdio(0),cout.tie(0)

typedef long long ll;
typedef unsigned long long ull;

using namespace std;


const ll N = 1000 + 5;

ll col[N],n,m,x,y;
ll pref[N];

ll dp[N][2];


ll solve(ll idx,ll colour){
    if(idx == m)
        return 0;
    
    

    ll &res = dp[idx][colour];
    if(~res)
        return res;

        
    res = 1e6;
    for(ll i = x;i<=y;i++){
        if(idx + i > m)
            break;
        ll z = pref[idx + i] - pref[idx];
        if(colour)
            z = i * n - z;
        res = min(res,z + solve(idx + i,!colour) );
    }
    return res;
}



signed main(void){

    #ifdef Khaled
        freopen("in.txt","r",stdin);
        //freopen("out.txt","w",stdout);
    #endif
    fast;


    memset(dp,-1,sizeof dp);

    cin >> n >> m >> x >> y;
    for(ll i = 0;i<n;i++){
        for(ll j = 0;j<m;j++){
            char c;
            cin >> c;
            col[j] += (c == '#');
        }
    }
    for(ll i = 1;i<=m;i++){
        pref[i] = pref[i - 1] + col[i - 1];
    }

    cout << min(solve(0,0),solve(0,1)) << endl;


}