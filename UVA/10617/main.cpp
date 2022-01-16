#include <bits/stdc++.h>
#ifndef Khaled
    #define endl '\n'
#endif
#define all(a) a.begin(),a.end()
#define fast cin.tie(0),ios::sync_with_stdio(0),cout.tie(0)

typedef long long ll;
typedef unsigned long long ull;

using namespace std;
const ll N = 60 + 5;

string s;
ll dp[N][N];



ll solve(ll i,ll j){
    if(i > j)
        return 0;
    if(i == j)
        return 1;

    ll &ret = dp[i][j];
    if(~ret)
        return ret;
    

    if(s[i] == s[j]){
        return ret = 1 + solve(i + 1,j) + solve(i,j - 1);
    }
    else{
        return ret = solve(i + 1,j) + solve(i,j - 1) - solve(i + 1,j - 1);
    }


}

signed main(void){

    #ifdef Khaled
        freopen("in.txt","r",stdin);
        //freopen("out.txt","w",stdout);
    #endif
    fast;

    ll t;
    cin >> t;
    while(t--){
        memset(dp,-1,sizeof dp);
        cin >> s;
        cout << solve(0,s.size() - 1) << endl;
    }



}   