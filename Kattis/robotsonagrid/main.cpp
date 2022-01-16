
#include <bits/stdc++.h>
#define all(x) x.begin(),x.end()
using namespace std;


typedef unsigned long long ull;
typedef long long ll;
typedef vector<vector<int>> vvi;
typedef vector<int> vi;

const int MOD = (1ll<<31) - 1;




int n;
int grid[1000][1000];
int vis[1000][1000];
int vis2[1000][1000];
int dp[1000][1000];





int valid(int x,int y){
    return x >= 0 && x < n && y >= 0 && y < n && grid[x][y];
}


int dfs(int i,int j){
    if(i == n-1 && j == n-1){
        return 1;
    }
    if(vis2[i][j]) return 0;
    vis2[i][j] = 1;
    int ch1=0,ch2=0,ch3=0,ch4=0;
    if(valid(i+1,j)) ch1 = dfs(i+1,j);
    if(valid(i,j+1)) ch2 = dfs(i,j+1);
    if(valid(i-1,j)) ch3 = dfs(i-1,j);
    if(valid(i,j-1)) ch4 = dfs(i,j-1);
    return ch1 || ch2 || ch3 || ch4;
}




int paths(int i,int j){
    if(i == n-1 && j == n-1){
        return 1;
    }

    if(vis[i][j]) return dp[i][j];

    vis[i][j] = 1;

    int ch1 = 0;
    int ch2 = 0;
    if(valid(i+1,j)) ch1 = paths(i+1,j);
    if(valid(i,j+1)) ch2 = paths(i,j+1);

    int & ret = dp[i][j];
    return ret = (0ll + ch1 + ch2) % MOD;


}



int main(void){
   
    #ifdef offline_vs_code
        freopen("out.txt","w",stdout);
        freopen("in.txt","r",stdin);
    #endif 

    cin >> n;
    for(int i = 0;i<n;i++){
        for(int j = 0;j<n;j++){
            char x;
            cin >> x;
            grid[i][j] = (x == '.');
        }
    }


    int res = paths(0,0);
    if(res)
        cout << res << '\n';
    else
        if(dfs(0,0))
            cout << "THE GAME IS A LIE\n";
        else 
            cout << "INCONCEIVABLE\n";



}   
