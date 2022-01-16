#include <bits/stdc++.h>
#ifndef Khaled
    #define endl '\n'
#endif
#define all(a) a.begin(),a.end()
#define fast cin.tie(0),ios::sync_with_stdio(0),cout.tie(0)

typedef long long ll;
typedef unsigned long long ull;

using namespace std;

const int N = 1e3 + 5;
const int MOD = 1e9 + 7;
int n,m;

int grid[N][N],dp[N][N];

int valid(int x,int y){
    return x >= 0 && x < n && y >= 0 && y < m;
}



int solve(int x,int y){
    if(x == n - 1 && y == m - 1)
        return 1;
    

    int &ret = dp[x][y];
    if(~ret)
        return ret;

    int ch1 = 0,ch2 = 0;
    if(valid(x + 1,y) && grid[x + 1][y])
        ch1 = solve(x + 1,y);
    if(valid(x,y + 1) && grid[x][y + 1])
        ch2 = solve(x,y + 1);
    
    return ret = (ch1 + ch2) % MOD;
}



signed main(void){

    #ifdef Khaled
        freopen("in.txt","r",stdin);
        //freopen("out.txt","w",stdout);
    #endif


    fast;


    memset(dp,-1,sizeof dp);

    cin >> n >> m;
    for(int i = 0;i<n;i++){
        for(int j = 0;j<m;j++){
            char c;
            cin >> c;
            grid[i][j] = (c == '.');
        }
    }
    cout << solve(0,0) << endl;



}