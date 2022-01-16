#include <bits/stdc++.h>
#ifndef Khaled
    #define endl '\n'
#endif
#define fast cin.tie(0),ios::sync_with_stdio(0),cout.tie();
#define all(a) a.begin(),a.end()

typedef long long ll;
typedef unsigned long long ull;

using namespace std;

const int N = 10;

char grid[N][N];
int n,m;
string s = "@IEHOVA#";

int valid(int i,int j){
    return i >= 0 && j >= 0 && i < n && j < m;
}

void dfs(int x,int y,int idx){
    if(idx + 1 == s.size()){
        cout << endl;
        return;
    }
    if(idx)
        cout << " ";

    if(valid(x - 1,y) && grid[x-1][y] == s[idx + 1]){
        cout << "forth";
        dfs(x - 1,y,idx + 1);
    }
    else if(valid(x,y + 1) && grid[x][y + 1] == s[idx + 1]){
        cout << "right";
        dfs(x,y + 1,idx + 1);
    }
    else{
        cout << "left";
        dfs(x,y - 1,idx + 1);
    }
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
        cin >> n >> m;
        int st;
        for(int i = 0;i<n;i++){
            for(int j = 0;j<m;j++){
                cin >> grid[i][j];
                if(grid[i][j] == '@')
                    st = i * m + j;
            }
        }
        dfs(st / m,st % m,0);
    }

}




