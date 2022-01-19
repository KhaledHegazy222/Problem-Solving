#include <bits/stdc++.h>
#ifndef Khaled
    #define endl '\n'
#endif
#define fast cin.tie(0),ios::sync_with_stdio(0),cout.tie();
#define all(a) a.begin(),a.end()

typedef long long ll;
typedef unsigned long long ull;

using namespace std;

const int N = 1e7 + 5;

const int MOD = 1e9 + 7;

int dp[4][N];


int solve(int n){


    for(int i = 0;i<4;i++){
        dp[i][0] = !i;
    }
    for(int i = 1;i<=n;i++){
        for(int j = 0;j < 4;j++){
            for(int k = 0;k < 4;k++){
                if(j == k)
                    continue;
                dp[j][i] = (0ll + dp[j][i] + dp[k][i - 1]) % MOD;
            }

        }
    }

    return dp[0][n];
}








signed main(void){

    #ifdef Khaled
        freopen("in.txt","r",stdin);
        //freopen("out.txt","w",stdout);
    #endif
    fast;
    int n;
    cin >> n;
    cout << solve(n);


}