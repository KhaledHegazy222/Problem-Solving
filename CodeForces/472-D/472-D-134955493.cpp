#include <bits/stdc++.h>
#define fast cin.tie(0),ios::sync_with_stdio(0),cout.tie();
#define all(a) a.begin(),a.end()

typedef long long ll;
typedef unsigned long long ull;

using namespace std;


const ll N = 2e3 + 5,M = 2 * N;

ll weights[N][N];
ll res[N][N];
struct DSU{
    ll par[N];

    DSU(ll n){
        iota(par,par + n,0);
    }


    ll find(ll x){
        if(x == par[x])
            return x;
        return par[x] = find(par[x]);
    }

    ll join(ll a,ll b){
        a = find(a);
        b = find(b);
        if(a == b)
            return 0;
        if(rand() % 2)
            swap(a,b);
        par[b] = a;
        return 1;
    }
};


struct ADJ{

    ll head[N],to[M],nxt[M],ne;
    ll cost[M];
    ADJ(ll n){
        memset(head,-1,(n + 1) * sizeof head[0]);
        ne = 0;
    }

    void addEdge(ll u,ll v,ll c){
        nxt[ne] = head[u];
        to[ne] = v;
        cost[ne] = c;
        head[u] = ne++;
    }

    void addBiEdge(ll u,ll v,ll c){
        addEdge(u,v,c);
        addEdge(v,u,c);
    }


    void bfs(ll src){
        fill(res[src],res[src + 1],1e9);

        res[src][src] = 0;
        queue<ll>q;
        q.push(src);
        while(q.size()){
            ll u = q.front();
            q.pop();
            for(ll e = head[u];~e;e = nxt[e]){
                ll v = to[e];
                ll c = cost[e];
                if(res[src][v] > res[src][u] + c){
                    res[src][v] = res[src][u] + c;
                    q.push(v); 
                }
            }
        }
    }
    
    
};


signed main(void){

    #ifdef Khaled
        freopen("in.txt","r",stdin);
        //freopen("out.txt","w",stdout);
    #endif
    #ifndef Khaled
        #define endl '\n'
        fast;
    #endif
    ll n;
    cin >> n;
    vector<pair<pair<ll,ll>,ll>>edges;
    for(ll i = 0;i<n;i++){
        for(ll j = 0;j < n;j++){
            cin >> weights[i][j];
            edges.push_back({{i,j},weights[i][j]});
        }
    }
    sort(all(edges),[](pair<pair<ll,ll>,ll>a,pair<pair<ll,ll>,ll>b){
        return a.second < b.second;
    });
    DSU D(n);
    ADJ adj(n);
    for(auto elem : edges){
        ll u = elem.first.first;
        ll v = elem.first.second;
        ll c = elem.second;
        if(D.join(u,v)){
            adj.addBiEdge(u,v,c);
        }
    }

    for(ll i = 0;i<n;i++){
        adj.bfs(i);
    }
    ll valid = 1;
    for(ll i = 0;i<n;i++){
        for(ll j = 0;j < n;j++){
            if(res[i][j] != weights[i][j])
                valid = 0;
            if(!res[i][j] && i != j)
                valid = 0;
        }
    }

    cout << (valid ? "YES\n" : "NO\n");


}