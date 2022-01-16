#include <bits/stdc++.h>
#define fast cin.tie(0),ios::sync_with_stdio(0),cout.tie();
#define all(a) a.begin(),a.end()

typedef long long ll;
typedef unsigned long long ull;

using namespace std;


ll n,s;

ll dp[66][66][2];

ll solve(ll idx,ll secured,ll last){
    if(!idx){
        return secured == s;
    }

    ll &ret = dp[idx][secured][last];
    if(~ret)
        return ret;

    ll ch1 = solve(idx - 1,secured - last,0);
    ll ch2 = solve(idx - 1,secured - 1,1);

    return ret = ch1 + ch2;

    
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
    while(cin >> n >> s, (n >= 0 && s >= 0)){
        memset(dp,-1,sizeof dp);
        cout << solve(n,n,0) << endl;
    }    

}


