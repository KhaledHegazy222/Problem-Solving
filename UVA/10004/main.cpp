
#include <bits/stdc++.h>
 
typedef unsigned long long ull;
typedef long long ll;
 
#define all(x) x.begin(),x.end()
#define pi (3.14159265)


using namespace std;


int visited[201];
int vid = 1;
bool dfs(vector<vector<int>>&map,int u,int colors[],int c){
    if(visited[u] == vid){
        return true;
    }
    visited[u] = vid;
    colors[u] = c;
    bool ret = true;
    for(int i = 0;i < map[u].size();i++){
        int v = map[u][i];
        if(colors[v] == colors[u]){
            return false;
        }
        ret = ret && dfs(map,v,colors,(c%2)+1);
        
    }
    return ret;
}

int main(void){
    cout.tie(0);
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    #ifdef offline_vs_code
        freopen("out.txt","w",stdout);
        freopen("in.txt","r",stdin);
    #endif 
    


    int n;
    while(cin >> n){
        if(!n){
            return 0;
        }
        int e;
        cin >> e;
        vector<vector<int>>map(n);
        while(e--){
            int a,b;
            cin >> a >> b;
            map[a].push_back(b);
            map[b].push_back(a);
        }
        int colors[n] = {0};
        if(dfs(map,0,colors,1)){
            cout << "BICOLORABLE.\n";
        }
        else{
            cout << "NOT BICOLORABLE.\n";
        }
        vid++;
    }
   


}

