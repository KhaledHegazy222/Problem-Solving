#include <bits/stdc++.h>
#ifndef Khaled
    #define endl '\n'
#endif
#define fast cin.tie(0),ios::sync_with_stdio(0),cout.tie();
#define all(a) a.begin(),a.end()

typedef long long ll;
typedef unsigned long long ull;

using namespace std;

const int N = 30 + 5;

int grid[N][N],n;


int dx[] = {0, 1, 0, -1, 1, 1, -1, -1};
int dy[] = {1, 0, -1, 0, 1, -1, 1, -1};


int valid(int x,int y){
    return x >= 0 && x < n && y >= 0 && y < n && grid[x][y];
}

void dfs(int x,int y){
    grid[x][y] = 0;
    for(int i = 0;i<sizeof(dx) / sizeof(dx[0]);i++){
        int xx = x + dx[i];
        int yy = y + dy[i];
        if(valid(xx,yy))
            dfs(xx,yy);
    }
}

int explore(){
    int cnt = 0;
    for(int i = 0;i<n;i++){
        for(int j = 0;j<n;j++){
            if(grid[i][j])
                cnt++,dfs(i,j);
        }
    }
    return cnt;
}



signed main(void){

    #ifdef Khaled
        freopen("in.txt","r",stdin);
        //freopen("out.txt","w",stdout);
    #endif
    fast;
    int cs = 1;
    while(cin >> n){
        for(int i = 0;i<n;i++){
            for(int j = 0;j<n;j++){
                char c;
                cin >> c;
                grid[i][j] = c - '0';
            }
        }
        cout << "Image number " << cs++ << " contains " << explore() << " war eagles.\n";
        
    }


}



