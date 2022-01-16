#include <bits/stdc++.h>
#ifndef Khaled
    #define endl '\n'
#endif
#define all(a) a.begin(),a.end()
#define fast cin.tie(0),ios::sync_with_stdio(0),cout.tie(0)

typedef long long ll;
typedef unsigned long long ull;

using namespace std;
const int N = 5e3 + 5;
int A[N],n,m,k;

ll pref[N];

ll dp[5001][5001];


ll solve(int idx,int groups){
    if(idx > n)
        return -1e15;
    if(idx == n)
        return groups == k ? 0 : -1e15;
    
    ll &ret = dp[idx][groups];
    if(~ret)
        return ret;

    ll ch1 = solve(idx + 1,groups);
    ll ch2 = -1e15;
    if(idx + m <= n)
        ch2 = pref[idx + m] - pref[idx] + solve(idx + m,groups + 1);
    
    return ret = max(ch1,ch2);

}



signed main(void){

    #ifdef Khaled
        freopen("in.txt","r",stdin);
        //freopen("out.txt","w",stdout);
    #endif
    fast;   

    memset(dp,-1,sizeof dp);
    
    cin >> n >> m >> k;
    for(int i = 0;i<n;i++)
        cin >> A[i];
    
    for(int i = 1;i<=n;i++)
        pref[i] = pref[i - 1] + A[i - 1];

    cout << solve(0,0) << endl;

}