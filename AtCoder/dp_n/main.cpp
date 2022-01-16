#include <bits/stdc++.h>
#ifndef Khaled
    #define endl '\n'
#endif
#define all(a) a.begin(),a.end()
#define fast cin.tie(0),ios::sync_with_stdio(0),cout.tie(0)

typedef long long ll;
typedef unsigned long long ull;

using namespace std;

const int N = 4e2 + 5;

int A[N],n;
ll pref[N];

ll dp[N][N];



ll solve(int st,int en){
    if(st == en){
        return 0;
    }

    ll &ret = dp[st][en];
    if(~ret)
        return ret;
    ret = 1e15;
    for(int i = st;i < en;i++){
        ret = min(ret,pref[en + 1] - pref[st] + solve(st,i) + solve(i + 1,en));
    }
    return ret;
}


signed main(void){

    #ifdef Khaled
        freopen("in.txt","r",stdin);
        //freopen("out.txt","w",stdout);
    #endif
    fast;
    cin >> n;
    for(int i = 0;i<n;i++)
        cin >> A[i];
    
    for(int i = 1;i <= n;i++)
        pref[i] = pref[i - 1] + A[i - 1];
    

    memset(dp,-1,sizeof dp);
    cout << solve(0,n - 1) << endl;


}