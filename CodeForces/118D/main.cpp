#include <bits/stdc++.h>
#define fast cin.tie(0),ios::sync_with_stdio(0),cout.tie();
#define all(a) a.begin(),a.end()

typedef long long ll;
typedef unsigned long long ull;

using namespace std;

const int MOD = 100000000;
ll dp[101][101][11][11][2];


ll solve(ll n1,ll n2,ll k1,ll k2,ll turn){
    if(!n1 && !n2)
        return 1;

    ll &res = dp[n1][n2][k1][k2][turn];
    if(~res)
        return res;
    res = 0;

    if(turn){
        for(ll i = 1;i<=min(k1,n1);i++){
            res = (res + solve(n1 - i,n2,k1,k2,!turn)) % MOD;
        }
        
        return res;
    }
    else{
        for(ll i = 1;i<=min(k2,n2);i++){
            res = (res + solve(n1,n2 - i,k1,k2,!turn)) % MOD;
        }
        return res;
    }
}

signed main(void){

    #ifdef Khaled
        freopen("in.txt","r",stdin);
        //freopen("out.txt","w",stdout);
    #endif
    #ifndef Khaled
        #define endl '\n'
        fast;
    #endif
    ll n1,n2,k1,k2;
    cin >> n1 >> n2 >> k1 >> k2;

    memset(dp,-1,sizeof dp);
    cout << (solve(n1,n2,k1,k2,0) + solve(n1,n2,k1,k2,1)) % MOD << endl;
}


