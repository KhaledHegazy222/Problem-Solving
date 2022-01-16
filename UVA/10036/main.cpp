#include <bits/stdc++.h>
#ifndef Khaled
    #define endl '\n'
#endif
#define all(a) a.begin(),a.end()
#define fast cin.tie(0),ios::sync_with_stdio(0),cout.tie(0)

typedef long long ll;
typedef unsigned long long ull;

using namespace std;

const int N = 1e4 + 5;

int A[N],n,k;

int dp[N][100 + 5];

int solve(int idx,int rem){
    if(idx == n){
        return !rem;
    }
    
    int &ret = dp[idx][rem];
    if(~ret)
        return ret;


    int ch1 = solve(idx + 1,(rem + A[idx]) % k);
    int ch2 = solve(idx + 1,((rem - A[idx]) % k + k ) % k);

    return ret = (ch1 || ch2);

}




signed main(void){

    #ifdef Khaled
        freopen("in.txt","r",stdin);
        //freopen("out.txt","w",stdout);
    #endif
    fast;

    int t;
    cin >> t;
    while(t--){
        memset(dp,-1,sizeof dp);
        cin >> n >> k;
        for(int i = 0;i<n;i++)
            cin >> A[i];
        cout << (solve(0,0) ? "Divisible\n" : "Not divisible\n");
    }

}