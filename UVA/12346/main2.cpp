#include <bits/stdc++.h>
#ifndef Khaled
    #define endl '\n'
#endif
#define all(a) a.begin(),a.end()
#define fast cin.tie(0),ios::sync_with_stdio(0),cout.tie(0)

typedef long long ll;
typedef unsigned long long ull;

using namespace std;

const int N = 20 + 1;
int rate[N],cost[N],n;

int needed,tim;

ll dp[N][1 << N];


ll solve(int idx,int mask,ll res,ll c){
    if(idx == n){
        if(res >= needed)
            return c;
        return 1e12;
    }

    ll &ret = dp[idx][mask];
    if(~ret)
        return ret;

    ll ch1 = solve(idx + 1,mask,res,c);
    ll ch2 = solve(idx + 1,mask | (1 << idx),res + rate[idx] * tim,c + cost[idx]);
    return ret = min(ch1,ch2);
}



signed main(void){

    #ifdef Khaled
        freopen("in.txt","r",stdin);
        //freopen("out.txt","w",stdout);
    #endif
    fast;
    cin >> n;
    for(int i = 0;i<n;i++)
        cin >> rate[i] >> cost[i];
    

    int m;
    cin >> m;
    for(int i = 1;i<=m;i++){
        memset(dp,-1,sizeof dp);
        cin >> needed >> tim;
        cout << "Case " << i << ": ";
        if(solve(0,0,0,0) < 1e11){
            cout << solve(0,0,0,0) << endl;
        }
        else{
            cout << "IMPOSSIBLE\n";
        }
    }


}//