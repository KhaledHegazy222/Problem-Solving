#include <bits/stdc++.h>
#define fast cin.tie(0),ios::sync_with_stdio(0),cout.tie();
#define all(a) a.begin(),a.end()

typedef long long ll;
typedef unsigned long long ull;

using namespace std;

string s;

ll dp[100005][3][3];


ll solve(ll idx,ll last,ll flip){
    if(idx == s.size())
        return 0;

    ll &ret = dp[idx][last][flip];
    if(~ret)
        return ret;
    if(flip == 1){
        ll ch1 = solve(idx,last,2);
        ll ch2 = 0;
        if(last == 2 || s[idx] - '0' == last)
            ch2 = 1 + solve(idx + 1,!(s[idx] - '0'),1);
        return ret = max(ch1,ch2);
    }
    else{
        ll ch1 = solve(idx + 1,last,flip);
        ll ch2 = 0;
        if(last == 2 || last != s[idx] - '0')
            ch2 = 1 + solve(idx + 1,s[idx] - '0',flip);
        ll ch3 = 0;
        if(!flip && (last == 2 || last == s[idx] - '0'))
            ch3 = 1 + solve(idx + 1,!(s[idx] - '0'),1);
        return ret = max({ch1,ch2,ch3});

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
    memset(dp,-1,sizeof dp);
    ll n;
    cin >> n;
    cin >> s;
    cout << solve(0,2,0) << endl;


}


