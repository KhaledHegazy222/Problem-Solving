

#include <bits/stdc++.h>
 
typedef unsigned long long ull;
typedef long long ll;
 
#define all(x) x.begin(),x.end()
#define pi (3.14159265)


using namespace std;

void dfs(vector<vector<int>>&tree,int u,int steps,int visited[],int dist[]){
    if(visited[u]){
        return;
    }
    visited[u] = 1;
    dist[u] = steps;
    for(int i = 0;i<tree[u].size();i++){
        int v = tree[u][i];
        dfs(tree,v,steps+1,visited,dist);
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



    int n;
    cin >> n;
    vector<vector<int>>v(n);
    for(int i = 0;i<n-1;i++){
        int a,b;
        cin >> a >> b;
        v[a-1].push_back(b-1);
        v[b-1].push_back(a-1);
    }
    int visited[n] = {0};
    int dist[n] = {0};
    dfs(v,0,0,visited,dist);
    int max_len = 0;
    int max_i = 0;
    for(int i = 0;i<n;i++){
        if(max_len < dist[i]){
            max_len = dist[i];
            max_i = i;
        }
    }
    memset(visited,0,sizeof visited);
    dfs(v,max_i,0,visited,dist);

    max_len = 0;
    for(int i = 0;i<n;i++){
        max_len = max(max_len,dist[i]);
    }
    cout << max_len;
    
}

