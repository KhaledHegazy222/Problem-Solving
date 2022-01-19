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

ll color[N],cost[N][N],n,m,k;


ll dp[N][N][N];


ll solve(ll idx,ll last,ll groups){
    if(idx == n){
        if(groups == k)
            return 0;
        return 1e15;
    }

    ll &ret = dp[idx][last][groups];
    if(~ret)
        return ret;

    if(!color[idx]){
        ret = 1e15;
        for(ll i = 1;i<=m;i++){
            ll add = 1;
            if(!last || last == i)
                add = 0;
            ret = min(ret,cost[idx][i - 1] + solve(idx + 1,i,groups + add));
        }
        return ret;
    }
    else{
        if(!last || color[idx] == last)
            return ret = solve(idx + 1,color[idx],groups);
        return ret = solve(idx + 1,color[idx],groups + 1);
    }
}


signed main(void){

    #ifdef Khaled
        freopen("in.txt","r",stdin);
        //freopen("out.txt","w",stdout);
    #endif
    fast;

    memset(dp,-1,sizeof dp);
    cin >> n >> m >> k;

    for(ll i = 0;i<n;i++)
        cin >> color[i];
    
    for(ll i = 0;i<n;i++){
        for(ll j = 0;j<m;j++)
            cin >> cost[i][j];
    }

    ll res = solve(0,0,1); 
    if(res > 1e12)
        cout << "-1\n";
    else
        cout << res << endl;

}