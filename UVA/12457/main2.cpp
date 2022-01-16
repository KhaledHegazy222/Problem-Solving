#include <bits/stdc++.h>
#ifndef Khaled
    #define endl '\n'
#endif
#define fast cin.tie(0),ios::sync_with_stdio(0),cout.tie();
#define all(a) a.begin(),a.end()

typedef long long ll;
typedef unsigned long long ull;

using namespace std;



double p;
const int N = 25 + 5;
double dp[2 * N][2 * N];


double solve(int rem,int wins){
    if(!rem){
        return wins > 0;
    }
    double &ret = dp[rem][wins];
    if(ret == ret)
        return ret;
    double ch1 = p * solve(rem - 1,wins + 1);
    double ch2 = (1.0 - p) * solve(rem - 1,wins - 1);
    return ret = ch1 + ch2;

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
        int n;
        cin >> n >> p;
        cout << fixed << setprecision(2) << solve(2 * n - 1,0) << endl;
    }
}

//
