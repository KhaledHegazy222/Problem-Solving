
#include <bits/stdc++.h>

#define all(a) a.begin(),a.end()
#define fast cin.tie(0),ios::sync_with_stdio(0),cout.tie(0)
#define ll long long 

using namespace std;


const int N = 1e2 + 5,M = 1e4 + 5;
int n,m;
int par[N];
int cost[M];

struct{
    
    int head[N],nxt[M],to[M],ne;

    void init(){
        ne = 0;
        memset(head,-1,(n + 1) * sizeof head[0]);
    }

    void addEdge(int u,int v,int c){
        cost[ne] = c;
        nxt[ne] = head[u];
        to[ne] = v;
        head[u] = ne++;
    }

    void addBiEdge(int u,int v,int c){
        addEdge(u,v,c);
        addEdge(v,u,c);
    }
}adj;

struct DSU{
        
    void init(){
        iota(par,par + n,0);
    }

    int find(int u){
        if(par[u] != u)
            return par[u] = find(par[u]);
        return par[u];
    }

    int join(int a,int b){
        int u = find(a);
        int v = find(b);
        if(u == v) return 0;
        if(rand() % 2) swap(u,v);
        par[v] = u;
        return 1;
    }

}dsu;



void kruskal(){
    dsu.init();
    vector<pair<int,pair<int,int>>>edges;
    for(int u = 0;u<n;u++){
        for(int e = adj.head[u];~e;e = adj.nxt[e]){
            int v = adj.to[e];
            edges.push_back({cost[e],{u,v}});
        }
    }
    sort(all(edges));
    map<set<pair<pair<int,int>,int >>,int>vals;
    int res = 0;
    set<pair<pair<int,int>,int >>st;
    for(int i = 0;i<adj.ne;i++){
        int u = edges[i].second.first;
        int v = edges[i].second.second;
        int c = edges[i].first;
        if(dsu.join(u,v))
            res += c,st.insert({{u,v},c});  
    }

    vals[st] = res;
    for(int j = 0;j<adj.ne;j++){
        dsu.init();
        int x = edges[j].first;
        edges[j].first = 1e5 + 5;
        sort(all(edges));
        res = 0;
        st.clear();
        for(int i = 0;i<adj.ne;i++){
            int u = edges[i].second.first;
            int v = edges[i].second.second;
            int c = edges[i].first;
            if(dsu.join(u,v))
                res += c,st.insert({{u,v},c});  
            
                
        }
        edges[adj.ne - 1].first = x;
        vals[st] = res;
    }
    vector<int>z;
    for(auto it : vals){
        z.push_back(it.second);
    }
    sort(all(z));
    cout << z[0] << " " << z[1] << endl;
}





int main(void){
    
	#ifdef Khaled
		freopen("in.txt","r",stdin);
		//freopen("out.txt","w",stdout);
	
    #endif


    int t;
    cin >> t;
    while(t--){
        cin >> n >> m;
        adj.init();
        for(int i = 0;i < m;i++){
            int a,b,c;
            cin >> a >> b >> c;
            a--,b--;
            adj.addEdge(a,b,c);           
        }
        kruskal();;
        
    }




}