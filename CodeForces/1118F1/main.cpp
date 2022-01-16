#include <bits/stdc++.h>
#ifndef Khaled
    #define endl '\n'
#endif
#define fast cin.tie(0),ios::sync_with_stdio(0),cout.tie();
#define all(a) a.begin(),a.end()

typedef long long ll;
typedef unsigned long long ull;

using namespace std;

const int N = 3e5 + 5,M = 2 * N;

int head[N],to[M],nxt[M],n,m,ne;

int color[N];

void init(){
    ne = 0;
    memset(head,-1,n * sizeof head[0]);
}

void addEdge(int f,int t){
    nxt[ne] = head[f];
    to[ne] = t;
    head[f] = ne++;
}

void addBiEdge(int u,int v){
    addEdge(u,v);
    addEdge(v,u);
}


int dfs(int u,int par,int nxtC,int val){
    if(color[u]){
        return color[u] == nxtC;
    }
    int ret = 0;
    for(int e = head[u];~e;e = nxt[e]){
        int v = to[e];
        if(v == par)
            continue;
        ret |= dfs(v,u,nxtC,val);
    }    
    if(ret)
        color[u] = val;
    return ret;
}

int cnt(int u,int par,int c){
    if(color[u] != c)
        return 0;
    int ret = 1;
    for(int e = head[u];~e;e = nxt[e]){
        int v = to[e];
        if(v == par)
            continue;
        ret += cnt(v,u,c);
    }
    return ret;
}



signed main(void){

    #ifdef Khaled
        freopen("in.txt","r",stdin);
        //freopen("out.txt","w",stdout);
    #endif
    fast;
    cin >> n;
    init();
    for(int i = 0;i<n;i++)
        cin >> color[i];
    for(int i = 0;i < n - 1;i++){
        int u,v;
        cin >> u >> v;
        addBiEdge(--u,--v);
    }

    for(int i = 0;i<n;i++){
        if(color[i]){
            int x = color[i];
            color[i] = 0;
            dfs(i,i,x,x);
            color[i] = x;
        }
    }
    int cntb = 0,cntr = 0;
    for(int i = 0;i<n;i++){
        if(!cntb && color[i] == 1)
            cntb = cnt(i,i,1);
        if(!cntr && color[i] == 2)
            cntr = cnt(i,i,2);  
    }
    cntb -= count(color,color + n,1);
    cntr -= count(color,color + n,2);
    if(cntb || cntr)
        return cout << 0 << endl,0;
    for(int i = 0;i<n;i++){
        if(color[i] == 1){
            color[i] = 0;
            dfs(i,i,2,3);
            color[i] = 1;
        }
    }
    int ans = count(color,color + n,3) + 1;
    cout << ans << endl;
    



}



