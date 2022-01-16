#include <bits/stdc++.h>
#ifndef Khaled
    #define endl '\n'
#endif
#define all(a) a.begin(),a.end()
#define fast cin.tie(0),ios::sync_with_stdio(0),cout.tie(0)

typedef long long ll;
typedef unsigned long long ull;

using namespace std;

const int N = 1e2 + 5;
int cost[N],n,x;

int dp[N][N * N];


int solve(int idx,int rem){
    if(idx == n)
        return 0;


    int &ret = dp[idx][rem];
    if(~ret)    
        return ret;
    
    int ch1 = solve(idx + 1,rem);
    int ch2 = 0;
    if(rem >= cost[idx] * (n - idx))
        ch2 = 1 + solve(idx + 1,rem - (cost[idx] * (n - idx)));
    
    return ret = max(ch1,ch2);
    
        
}


signed main(void){

    #ifdef Khaled
        freopen("in.txt","r",stdin);
        //freopen("out.txt","w",stdout);
    #endif
 
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);

    fast;


    memset(dp,-1,sizeof dp);

    cin >> n >> x;
    for(int i = 0;i<n;i++)
        cin >> cost[i];

    cout << solve(0,x) << endl;


}