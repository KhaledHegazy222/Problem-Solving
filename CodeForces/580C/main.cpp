
#include <bits/stdc++.h>
 
typedef unsigned long long ull;
typedef long long ll;
 
#define all(x) x.begin(),x.end()
#define pi (3.14159265)
#define MAX 100000

using namespace std;

vector<vector<int>>tree(MAX);
int cats[MAX];
int visited[MAX];
int n,m;



int dfs(int u,int passed){
    if(visited[u]){
        return 0;
    }
    visited[u] = 1;
    if(passed + cats[u] > m){
        return 0;
    }
    int send = 0;
    if(cats[u]){
        send = passed+1;
    }
    int leaf = 1;
    int cnt = 0;
    for(int i = 0;i<tree[u].size();i++){
        int v = tree[u][i];
        if(!visited[v]){
            cnt += dfs(v,send);
            leaf = 0;
        }
    }
    if(leaf) {
        return 1;
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


    cin >> n >> m;
    for(int i = 0;i<n;i++){
        cin >> cats[i];
    }

    for(int i = 0;i<n;i++){
        int a,b;
        cin >> a >> b;
        tree[a-1].push_back(b-1);
        tree[b-1].push_back(a-1);
    }



    cout << dfs(0,0) <<endl;


    
}

