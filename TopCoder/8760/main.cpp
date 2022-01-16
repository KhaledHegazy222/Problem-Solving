
#include <bits/stdc++.h>

#define all(a) a.begin(),a.end()
#define fast cin.tie(0),ios::sync_with_stdio(0),cout.tie(0)
#define ll long long 

using namespace std;

int s,k;

ll dp[21][101];


ll solve(int idx,int rem){
    if(idx == k){
        return rem == 0;
    }
    
    ll &ret = dp[idx][rem];
    if(~ret) return ret;
    ret = 0;
    for(int i = 1;i<= rem;i++)
        ret = max(ret,1ll * i * solve(idx + 1,rem - i));
    
    return ret;
}


class MaximalProduct{
    public:
    ll maximalProduct(int a,int b){
        memset(dp,-1,sizeof dp);
        s = a,k = b;
        return solve(0,s);
    }
};

