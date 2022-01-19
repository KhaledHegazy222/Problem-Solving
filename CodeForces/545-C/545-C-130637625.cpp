#include <bits/stdc++.h>
#ifndef Khaled
    #define endl '\n'
#endif
#define all(a) a.begin(),a.end()
#define fast cin.tie(0),ios::sync_with_stdio(0),cout.tie(0)

typedef long long ll;
typedef unsigned long long ull;

using namespace std;


const ll N = 1e5 + 5;

ll x[N],h[N],n;

int dp[N][2];

int solve(int idx,int last){
    if(idx == n)
        return 1;
    
    int &ret = dp[idx][last];
    if(~ret)
        return ret;

    int ch1 = solve(idx + 1,0);
    int ch2 = 0,ch3 = 0;
    if(last){
        if(x[idx] - h[idx] > x[idx - 1] + h[idx - 1])
            ch2 = 1 + solve(idx + 1,0);
    }
    else{
        if(x[idx] - h[idx] > x[idx - 1])
            ch2 = 1 + solve(idx + 1,0);
    }

    if(x[idx] + h[idx] < x[idx + 1])
        ch3 = 1 + solve(idx + 1,1);


    return ret = max({ch1,ch2,ch3});
}


signed main(void){

    #ifdef Khaled
        freopen("in.txt","r",stdin);
        //freopen("out.txt","w",stdout);
    #endif
    fast;


    memset(dp,-1,sizeof dp);

    cin >> n;
    x[0] = -1e10;
    h[0] = 0;
    for(ll i = 1;i<=n;i++){
        cin >> x[i] >> h[i];
    }

    cout << solve(1,0) << endl;



}