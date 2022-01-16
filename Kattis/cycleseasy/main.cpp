

#include <bits/stdc++.h>
 
typedef unsigned long long ull;
typedef long long ll;
 
#define all(x) x.begin(),x.end()
#define pi (3.14159265)
#define MAX 100000

using namespace std;
const int N = 15;

int Mat[N][N];
int n;
int vis[N],vid;

int dfs(int u){
    if(vis[u] == vid) return 0;
    vis[u] = vid;
    int ret = 0;
    bool enter = false;
    for(int v = 0;v<n;v++){
        if (v == u || Mat[u][v] == vid){
            continue;
        }
        if(vis[v] != vid){
            enter = true;
            ret += dfs(v);
        }
    }
    vis[u] = 0;
    if(enter == false){
        for(int i = 0; i<n;i++){
            if(vis[i] != vid && i != u) return 0;
        }
        if(Mat[0][u] == vid) return 0;
        return 1;
    }
    else{
        return ret;
    }
}






int main(void){
    cout.tie(0);
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    #ifdef offline_vs_code
        freopen("out.txt","w",stdout);
        freopen("in.txt","r",stdin);
    #endif 
    
    



    int t;
    cin >> t;
    int cs = 1;
    while(t--){
        vid++;
        int e;
        cin >> n >> e;
        while(e--){
            int l,r;
            cin >> l >> r;
            Mat[--l][--r] = vid;
            Mat[r][l] = vid;
        }   
        cout << "Case #" << cs++ << ": " <<  ((dfs(0)+1) / 2 ) % 9901<< endl;
    }


}

