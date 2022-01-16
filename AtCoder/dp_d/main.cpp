#include <bits/stdc++.h>
#ifndef Khaled
    #define endl '\n'
#endif
#define all(a) a.begin(),a.end()
#define fast cin.tie(0),ios::sync_with_stdio(0),cout.tie(0)

typedef long long ll;
typedef unsigned long long ull;

using namespace std;

const int N = 1e2 + 5,W = 1e5 + 5;

int weight[N],val[N],n,w;


ll dp[N][W];

ll solve(int idx,int rem){
    if(idx == n)
        return 0;
    

    ll &ret = dp[idx][rem];

    if(~ret)
        return ret;

    ll ch1 = solve(idx + 1,rem);
    ll ch2 = 0;
    if(rem >= weight[idx])
        ch2 = val[idx] + solve(idx + 1,rem - weight[idx]);

    return ret = max(ch1,ch2);

}

signed main(void){

    #ifdef Khaled
        freopen("in.txt","r",stdin);
        //freopen("out.txt","w",stdout);
    #endif
    fast;

    memset(dp,-1,sizeof dp);
    cin >> n >> w;
    for(int i = 0;i<n;i++){
        cin >> weight[i] >> val[i];
    }

    cout << solve(0,w) << endl;


}