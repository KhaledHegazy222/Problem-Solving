

#include <bits/stdc++.h>
 
typedef unsigned long long ull;
typedef long long ll;
 
#define all(x) x.begin(),x.end()
#define pi (3.14159265)


using namespace std;

int dfs(vector<vector<int> >&v,int u,int visited[]){
    if(visited[u]){
        return 0;
    }
    visited[u] = 1;
    int cnt = 1;
    for(int i = 0;i<v[u].size();i++){
        int t = v[u][i];
        cnt += dfs(v,t,visited);
    }
    return cnt;
}



int main(void){
    cout.tie(0);
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    #ifdef offline_vs_code
        freopen("out.txt","w",stdout);
        freopen("in.txt","r",stdin);
    #endif 
    

    int n,e;
    cin >> n >> e;
    vector<vector<int> >v(n);
    for(int i = 0;i<e;i++){
        int a,b;
        cin >> a >> b;
        v[a-1].push_back(b-1);
        v[b-1].push_back(a-1);
    }
    int visited[n] = {0};
    if(e == n-1 && dfs(v,0,visited) == n){
        cout << "YES\n";
    }
    else{
        cout << "NO\n";
    }

}

