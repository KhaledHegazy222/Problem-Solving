#include <bits/stdc++.h>
#ifndef Khaled
    #define endl '\n'
#endif
#define all(a) a.begin(),a.end()
#define fast cin.tie(0),ios::sync_with_stdio(0),cout.tie(0)

typedef long long ll;
typedef unsigned long long ull;

using namespace std;

const ll N = 50 + 1;


ll A[N],n;

ll dp[N][N];



ll solve(ll st,ll en){
    if(st + 1 == en)
        return 0;
    
    ll &ret = dp[st][en];
    if(~ret)
        return ret;
    ret = 0;
    for(ll i = st + 1;i<en;i++){
        ret = max(ret,A[st] * A[en] + solve(st,i) + solve(i,en));
    }
    return ret;
}

class CasketOfStar{
    public :
    int maxEnergy(vector<int>v){
        n = v.size();
        for(int i = 0;i<n;i++)
            A[i] = v[i];
        
        memset(dp,-1,sizeof dp);
        return (int)solve(0,n - 1);
    }
};
