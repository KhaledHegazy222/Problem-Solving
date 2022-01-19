#include <bits/stdc++.h>
#ifndef Khaled
    #define endl '\n'
#endif
#define all(a) a.begin(),a.end()
#define fast cin.tie(0),ios::sync_with_stdio(0),cout.tie(0)

typedef long long ll;
typedef unsigned long long ull;

using namespace std;

const int N = 100,M = 1e2 * 1e2 * 10 * 2;
int A[N],B[N],n,k;


int dp[N][M];




int solve(int idx,int sum){
    if(idx == n)
        return sum ? -1e6 : 0;


    int &ret = dp[idx][sum + M / 2];
    if(~ret) 
        return ret;
    
    int ch1 = solve(idx + 1,sum);
    int ch2 = A[idx] + solve(idx + 1,sum + k * B[idx] - A[idx]);
    return ret = max(ch1,ch2);
}




signed main(void){

    #ifdef Khaled
        freopen("in.txt","r",stdin);
        //freopen("out.txt","w",stdout);
    #endif
    fast;

    memset(dp,-1,sizeof dp);

    cin >> n >> k;
    for(int i = 0;i<n;i++)
        cin >> A[i];
    for(int i = 0;i<n;i++)
        cin >> B[i];
    
    if(solve(0,0))
        cout << solve(0,0) << endl;
    else
        cout << -1 << endl;


}