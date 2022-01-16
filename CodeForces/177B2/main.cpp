#include <bits/stdc++.h>
#define fast cin.tie(0),ios::sync_with_stdio(0),cout.tie();
#define all(a) a.begin(),a.end()

typedef long long ll;
typedef unsigned long long ull;

using namespace std;


map<ll,ll>dp;


ll solve(ll n){
    if(n == 1){
        return 1;
    }

    if(dp.find(n) != dp.end())
        return dp[n];

    ll ret = 1;
    for(ll i = 2;i * i <= n;i++){
        if(n % i == 0){
            ret = max(ret,solve(n / i));
        }
    }
    dp.insert({n,ret + n});
    return ret + n;
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


    ll n;
    cin >> n;
    cout << solve(n) << endl;
    

}


