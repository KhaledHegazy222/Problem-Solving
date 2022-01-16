#include <bits/stdc++.h>
#ifndef Khaled
    #define endl '\n'
#endif
#define fast cin.tie(0),ios::sync_with_stdio(0),cout.tie();
#define all(a) a.begin(),a.end()

typedef long long ll;
typedef unsigned long long ull;

using namespace std;

const ll N = 1e6 + 5,M = N;

ll head[N],to[M],nxt[M],n,m,ne;
int inDeg[N],res[N],resSz;
void init(){
    ne = 0;
    memset(head,-1,(n + 1) * sizeof head[0]);
    memset(inDeg,0,sizeof inDeg);
    resSz = 0;
}


void addEdge(ll u,ll v){
    nxt[ne] = head[u];
    to[ne] = v;
    head[u] = ne++;
    inDeg[v]++;
}


void topo(){
    queue<int>pq;
    for(int i = 0;i<n;i++)
        if(!inDeg[i])
            pq.push(i);
    while(pq.size()){
        int u = pq.front();
        res[resSz++] = u;
        pq.pop();
        for(int e = head[u];~e;e = nxt[e]){
            int v = to[e];
            if(!--inDeg[v])
                pq.push(v);
        }
    }
}




signed main(void){

    #ifdef Khaled
        freopen("in.txt","r",stdin);
        //freopen("out.txt","w",stdout);
    #endif
    fast;
    while(cin >> n >> m,(n || m)){
        init();
        while(m--){
            int u,v;
            cin >> u >> v;
            addEdge(--u,--v);
        }
        topo();
        if(resSz != n){
            cout << "IMPOSSIBLE" << endl;
        }
        else{
            for(int i = 0;i<resSz;i++)
                cout << res[i] + 1 << endl;
        }
    }
}




  	 						  	 	 							 			 	