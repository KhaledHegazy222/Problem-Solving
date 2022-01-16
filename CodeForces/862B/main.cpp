#include <bits/stdc++.h>
#ifndef Khaled
    #define endl '\n'
#endif
#define fast cin.tie(0),ios::sync_with_stdio(0),cout.tie();
#define all(a) a.begin(),a.end()

typedef long long ll;
typedef unsigned long long ull;

using namespace std;

const ll N = 1e5 + 5,M = 2 * N;

ll head[N],to[M],nxt[M],n,m,ne;

void init(){
    ne = 0;
    memset(head,-1,(n + 1) * sizeof head[0]);
}


void addEdge(ll u,ll v){
    nxt[ne] = head[u];
    to[ne] = v;
    head[u] = ne++;
}

void addBiEdge(ll u,ll v){
    addEdge(u,v);
    addEdge(v,u);
}

ll dfs(ll u,ll par,ll c,ll &w,ll &b){
    ll ret = 0;
    ll ch = 0;
    for(ll e = head[u];~e;e = nxt[e]){
        ll v = to[e];
        if(v == par)
            continue;
        ch++;
        ll x = 0,y = 0;
        ret += dfs(v,u,!c,x,y);     
        w += x;
        b += y;
    }
    if(c){
        ret += b - ch;
        w++;
    }   
    else{
        ret += w - ch;
        b++;
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
    for(ll i = 0;i<n - 1;i++){
        ll u,v;
        cin >> u >> v;
        addBiEdge(--u,--v);
    }
    ll x = 0,y = 0;
    dfs(0,-1,0,x,y);
    cout << x * y - n + 1 << endl;
}




  	 						  	 	 							 			 	