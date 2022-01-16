#include <bits/stdc++.h>

#ifndef Khaled
    #define endl '\n'
#endif
#define all(a) a.begin(),a.end()
#define fast cin.tie(0),ios::sync_with_stdio(0),cout.tie(0)

typedef long long ll;
typedef unsigned long long ull;

using namespace std;

const ll N = 1e2 + 5,V = 1e5 + 5;
ll weight[N],val[N],n,w;

ll dp[N][V];


ll solve(ll idx,ll remVal){
    if(idx == n){
        return remVal ? 1e15 : 0;
    }
    
    ll &ret = dp[idx][remVal];
    if(~ret)
        return ret;

    ll ch1 = solve(idx + 1,remVal);
    ll ch2 = INT_MAX;
    if(remVal >= val[idx])
        ch2 = weight[idx] + solve(idx + 1,remVal - val[idx]);

    
    return ret = min(ch1,ch2);

}




signed main(void){

    #ifdef Khaled
        freopen("in.txt","r",stdin);
        //freopen("out.txt","w",stdout);
    #endif
    #ifndef Khaled
        fast;
    #endif


    memset(dp,-1,sizeof dp);

    cin >> n >> w;
    for(ll i = 0;i<n;i++)
        cin >> weight[i] >> val[i];

    for(ll i = V - 1;i>=0;i--){
        if(solve(0,i) <= w){
            cout << i << endl;
            break;
        }
    }


}