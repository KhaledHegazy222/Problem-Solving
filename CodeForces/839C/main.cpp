
#include <bits/stdc++.h>
#define all(x) x.begin(),x.end()
using namespace std;


typedef unsigned long long ull;
typedef long long ll;
typedef vector<vector<int>> vvi;
typedef vector<int> vi;




int MOD = 1e9+7;
int n,m,k;


vvi graph(100000);
int vis[100000];




double dfs(int u,int len){
    if(vis[u]) return 0;
    vis[u] = 1;
    double ret = 0;
    int going = 0;
    
    for(int i = 0;i<graph[u].size();++i){
        int v = graph[u][i];
        if(!vis[v]) going++;
    }
    for(int i = 0;i<graph[u].size();++i){
        int v =  graph[u][i];
        if(!vis[v])
            ret += (1.0)/going * dfs(v,len+1);
    }
    if(going == 0) return len;
    return ret;
}


int main(void){
   
    #ifdef offline_vs_code
        freopen("out.txt","w",stdout);
        freopen("in.txt","r",stdin);
    #endif 
    int n;
    cin >> n;
    for(int i = 0;i<n-1;i++){
        int a,b;
        cin >> a >> b;
        a--,b--;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }

    cout << fixed << setprecision(9) << dfs(0,0) << '\n';



    
}   
