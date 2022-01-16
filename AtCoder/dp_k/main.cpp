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

int A[N],n;

int dp[100005];


int solve(int rem){
    

    int &ret = dp[rem];
    if(~ret)
        return ret;

    ret = 0;
    for(int i = 0;i<n;i++){
        if(rem >= A[i])
            ret |= !solve(rem - A[i]);
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
    int k;
    cin >> n >> k;
    for(int i = 0;i<n;i++)
        cin >> A[i];
    
    cout << (solve(k) ? "First\n" : "Second\n");

}