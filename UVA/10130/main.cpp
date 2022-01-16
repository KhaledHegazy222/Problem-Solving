#include <bits/stdc++.h>
#ifndef Khaled
    #define endl '\n'
#endif
#define all(a) a.begin(),a.end()
#define fast cin.tie(0),ios::sync_with_stdio(0),cout.tie(0)

typedef long long ll;
typedef unsigned long long ull;

using namespace std;
const int N = 1e3 + 5,W = 30 + 4;

int price[N],weight[N],n;

int dp[N][W];


int solve(int idx,int rem){
    if(idx == n)
        return 0;


    int &ret = dp[idx][rem];
    if(~ret)
        return ret;

    int ch1 = solve(idx + 1,rem);
    int ch2 = 0;
    if(rem >= weight[idx])
        ch2 = price[idx] + solve(idx + 1,rem - weight[idx]);

    return ret = max(ch1,ch2);
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
        cin >> n;
        for(int i = 0;i<n;i++)
            cin >> price[i] >> weight[i];

        int g;
        cin >> g;
        int res = 0;
        while(g--){
            int w;
            cin >> w;
            res += solve(0,w);
        }
        cout << res << endl;
    }


}