#include <bits/stdc++.h>
#ifndef Khaled
    #define endl '\n'
#endif
#define all(a) a.begin(),a.end()
#define fast cin.tie(0),ios::sync_with_stdio(0),cout.tie(0)

typedef long long ll;
typedef unsigned long long ull;

using namespace std;
const int N = 1e5 + 5;

int frq[N],n;

ll dp[N];

ll solve(int idx){
    if(idx >= N)
        return 0;
    
    ll &ret = dp[idx];
    if(~ret)
        return ret;


    ll ch1 = 1ll * frq[idx] * idx + solve(idx + 2);
    ll ch2 = solve(idx + 1);
    return ret = max(ch1,ch2); 
}



signed main(void){

    #ifdef Khaled
        freopen("in.txt","r",stdin);
        //freopen("out.txt","w",stdout);
    #endif
    fast;
    cin >> n;
    for(int i = 0;i<n;i++){
        int c;
        cin >> c;
        frq[c]++;
    }
    memset(dp,-1,sizeof dp);
    cout << solve(0) << endl; 


}