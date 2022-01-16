#include <bits/stdc++.h>
#ifndef Khaled
    #define endl '\n'
#endif
#define all(a) a.begin(),a.end()
#define fast cin.tie(0),ios::sync_with_stdio(0),cout.tie(0)

typedef long long ll;
typedef unsigned long long ull;

using namespace std;

const int N = 1e2 + 5;

int grid[N][N],n,m;


int valid(int x,int y){
    return x >= 0 && x < n && y >= 0 && y < m;
}

int dp[N][N];

int solve(int x,int y){
    if(x == n - 1)
        return grid[x][y];
    

    int &ret = dp[x][y];

    if(~ret)   
        return ret;

    ret = 0;
    if(valid(x + 1,y))
        ret = max(ret,solve(x + 1,y));
    if(valid(x + 1,y + 1))
        ret = max(ret,solve(x + 1,y + 1));
    if(valid(x + 1,y - 1))
        ret = max(ret,solve(x + 1,y - 1));
    ret += grid[x][y];

    return ret;
    
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
        cin >> n >> m;
        for(int i = 0;i<n;i++)
            for(int j = 0;j<m;j++)
                cin >> grid[i][j];
        
        int sol = 0;
        for(int i = 0;i<m;i++){
            sol = max(sol,solve(0,i));
        }
        cout << sol << endl;
    }


}