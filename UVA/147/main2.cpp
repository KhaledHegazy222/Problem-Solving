#include <bits/stdc++.h>
#ifndef Khaled
    #define endl '\n'
#endif
#define fast cin.tie(0),ios::sync_with_stdio(0),cout.tie();
#define all(a) a.begin(),a.end()

typedef long long ll;
typedef unsigned long long ull;

using namespace std;
const ll N = 11 + 5;

ll coins[] = {5,10,20,50,100,200,500,1000,2000,5000,10000};

ll dp[N][30000 + 400];

ll solve(ll idx,ll rem){
    if(idx == sizeof(coins) / sizeof(coins[0]))
        return !rem;
    
    ll &ret = dp[idx][rem];
    if(~ret)
        return ret;
    ll ch1 = solve(idx + 1,rem);
    ll ch2 = 0;
    if(coins[idx] <= rem)
        ch2 = solve(idx,rem - coins[idx]);
    return ret = ch1 + ch2;


}



signed main(void){

    #ifdef Khaled
        freopen("in.txt","r",stdin);
        //freopen("out.txt","w",stdout);
    #endif
    fast;
    ll n;

    memset(dp,-1,sizeof dp);


    while(1){
        ll a,b;
        char _;

        cin >> a >> _ >> b;
        n = a * 100 + b;
        if(!n)
            return 0;
        stringstream ss;
        ss << a << _ << (b / 10) << (b % 10);
        cout << right << setw(6) << ss.str();
        cout << right << setw(17) << solve(0,n) << endl;
    }






}



