#include <bits/stdc++.h>
#define fast cin.tie(0),ios::sync_with_stdio(0),cout.tie();
#define all(a) a.begin(),a.end()

typedef long long ll;
typedef unsigned long long ull;

using namespace std;


string s;


ll dp[201][201];

ll solve(ll st,ll en,ll res){
    if(en - st >= 2 && !res)
        return -1e15;
    if(res > (1ll << 31) - 1)
        return -1e15;
    if(en == s.size()){
        return res;
    }

    ll &ret = dp[st][en];
    if(~ret)
        return ret;
    ll ch1 = 0;
    ll ch2 = 0;
    ch1 = solve(st,en + 1,res * 10 + (s[en] - '0'));
    ch2 = res + solve(en,en + 1,s[en] - '0');
    
    return ret = max(ch1,ch2);


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
    // cout << INT_MAX << endl;
    ll t;
    cin >> t;
    while(t--){
        memset(dp,-1,sizeof dp);
        cin >> s;
        // s = to_string(INT_MAX);
        cout << solve(0,0,0) << endl;
    }

}


