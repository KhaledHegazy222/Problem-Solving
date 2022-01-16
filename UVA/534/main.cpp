#include <bits/stdc++.h>
#define fast cin.tie(0),ios::sync_with_stdio(0),cout.tie();
#define all(a) a.begin(),a.end()

typedef long long ll;
typedef unsigned long long ull;

using namespace std;


const ll N = 200 + 5,M = 2 * N;


struct POll{
    ll x,y;
    double dist(POll A){
        return sqrt((x - A.x) * (x - A.x) + (y - A.y) * (y - A.y));
    }
}A[N];


struct ADJ{

    ll head[N],nxt[M],to[M],ne,n;
    double cost[M];

    void init(){
        memset(head,-1,(n + 1) * sizeof (head[0]));
        ne = 0;
    }

    void addEdge(ll u,ll v,double c){

        cost[ne] = c;
        nxt[ne] = head[u];
        to[ne] = v;
        head[u] = ne++;
        
    }

    void addBiEdge(ll u,ll v,double c){
        addEdge(u,v,c);
        addEdge(v,u,c);
    }


    double dfs(ll u,ll par,double mx){
        if(u == 1)
            return mx;



        double ret = 0;
        for(ll e = head[u];~e;e = nxt[e]){
            ll v = to[e];
            if(v == par)    
                continue;
            ret = max(ret,dfs(v,u,max(mx,cost[e])));
        }
        return ret;

    }
    




}adj;


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


    ll merge(ll a,ll b){
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



signed main(void){

    #ifdef Khaled
        freopen("in.txt","r",stdin);
        //freopen("out.txt","w",stdout);
    #endif
    #ifndef Khaled
        #define endl '\n'
        fast;
    #endif

    ll cs = 1;
    while(cin >> adj.n , adj.n){
        adj.init(); 
        for(ll i = 0;i<adj.n;i++){
            cin >> A[i].x >> A[i].y;
        }

        vector<pair<pair<ll,ll>,double>>edges;
        for(ll i = 0;i < adj.n;i++){
            for(ll j = i + 1;j < adj.n;j++){
                edges.push_back({{i,j},A[i].dist(A[j])});
            }
        }
        sort(all(edges),[](pair<pair<ll,ll>,double> &a,pair<pair<ll,ll>,double> &b){
            return a.second < b.second;
        });
        DSU D(adj.n);
        for(auto elem : edges){
            if(D.merge(elem.first.first,elem.first.second))
                adj.addBiEdge(elem.first.first,elem.first.second,elem.second);
        }

        double res = adj.dfs(0,-1,0);


        cout << "Scenario #" << cs++ << endl;
        cout << "Frog Distance = " << fixed << setprecision(3) << res << endl;

        cout << endl;


    }


}


