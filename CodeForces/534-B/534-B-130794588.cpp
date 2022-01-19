#include <bits/stdc++.h>
#ifndef Khaled
    #define endl '\n'
#endif
#define all(a) a.begin(),a.end()
#define fast cin.tie(0),ios::sync_with_stdio(0),cout.tie(0)

typedef long long ll;
typedef unsigned long long ull;

using namespace std;

int en,d;

int dp[2000][102];


int solve(int v,int tim){
    if(!tim)
        return (v == en ? 0 : -1e9);
    if(v < 0)
        return -1e9;
    int &ret = dp[v][tim];
    if(~ret)
        return ret;
    ret = -1e9;
    for(int i = -d;i<=d;i++){
        ret = max(ret,v + i + solve(v + i,tim - 1));
    }
    return ret;
}




signed main(void){

    #ifdef Khaled
        freopen("in.txt","r",stdin); 
        //freopen("out.txt","w",stdout);
    #endif
    fast;

    memset(dp,-1,sizeof dp);

    int st,t;
    cin >> st >> en >> t >> d;
    cout << solve(st,t-1) + st << endl;

}