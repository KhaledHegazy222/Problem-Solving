#include <bits/stdc++.h>
#ifndef Khaled
    #define endl '\n'
#endif
#define fast cin.tie(0),ios::sync_with_stdio(0),cout.tie();
#define all(a) a.begin(),a.end()

typedef long long ll;
typedef unsigned long long ull;

using namespace std;


const int N = 8 + 2;

int dist[N][N];
int dx[] = {2,2,-2,-2,1,1,-1,-1};
int dy[] = {1,-1,1,-1,2,-2,2,-2};

int valid(int i,int j){
    return i >= 0 && i < 8 && j >= 0 && j < 8;
}


void bfs(int i,int j){
    memset(dist,0x3f,sizeof dist);
    dist[i][j] = 0;
    queue<pair<int,int>>q;
    q.push({i,j});
    while(q.size()){
        auto u = q.front();
        q.pop();
        for(int k = 0;k<sizeof(dx) / sizeof(dx[0]);k++){
            int ii = u.first + dx[k];
            int jj = u.second + dy[k];
            if(valid(ii,jj) && dist[ii][jj] > dist[u.first][u.second] + 1){
                dist[ii][jj] = dist[u.first][u.second] + 1;
                q.push({ii,jj});
            }
        }
    }


}







signed main(void){

    #ifdef Khaled
        freopen("in.txt","r",stdin);
        //freopen("out.txt","w",stdout);
    #endif
    fast;
    
    string st,en;
    while(cin >> st >> en){
        int is = st[0] - 'a';
        int js = st[1] - '1';
        int ie = en[0] - 'a';
        int je = en[1] - '1';
        bfs(is,js);
        cout << "To get from " << st <<  " to " << en << " takes " << dist[ie][je] << " knight moves.\n";
        
    }
}



