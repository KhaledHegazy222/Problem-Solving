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


int grid[N][N],n,m;
ll dp[N][N];

int valid(int x,int y){
    return x >= 0 && y >= 0 && x < n && y < m;
}


ll solve(int x,int y){
    if(x == n - 1 && y == m - 1)
        return 1;
    
    ll &ret = dp[x][y];
    if(~ret)
        return ret;
    ret = 0;
    if(valid(x + 1,y) && !grid[x + 1][y])
        ret  += solve(x + 1,y);
        
    if(valid(x,y + 1) && !grid[x][y + 1])
        ret  += solve(x,y + 1);

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
        memset(grid,0,sizeof grid);
        memset(dp,-1,sizeof dp);
        cin >> n >> m;
        for(int i = 0;i<n;i++){
            int id;
            cin >> id;
            id--;
            string line;
            getline(cin,line);
            stringstream ss(line);
            int x;
            while(ss >> x){
                grid[id][--x] = 1;
            }
        }
        cout << solve(0,0) << endl;
        if(t)
            cout << endl;
    }



}