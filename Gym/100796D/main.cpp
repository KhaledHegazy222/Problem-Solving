#include <bits/stdc++.h>
#define endl '\n'
#define all(a) a.begin(),a.end()
#define fast cin.tie(0),ios::sync_with_stdio(0),cout.tie(0)

typedef long long ll;
typedef unsigned long long ull;

using namespace std;

const ll NN = 1e6 + 5,M = 2e6 +5;
ll head[NN],nxt[M],to[M],cost[M],nn,ne;
ll dis[NN], notVis[NN], notVisSz;

void init(){    
    memset(head,-1,(nn + 1) * sizeof head[0]);
    ne = 0;
}
void addEdge(ll f,ll t,ll c){
    cost[ne] = c;
    nxt[ne] = head[f];
    to[ne] = t;
    head[f] = ne++;    
}

void ShortestPath ( ll src ){
    memset ( dis , 0x3f , sizeof (dis[0])*nn ) ;
    dis[src] = 0 ;
    priority_queue <pair<ll,ll>> pq ;
    pq.push(make_pair(0,src)) ;
    while ( pq.size() ){
        ll u , d ;
        d = -pq.top().first ;
        u = pq.top().second ;
        pq.pop() ;
        if ( d != dis[u] )
            continue ;
        for ( ll e = head[u] ; ~e ; e = nxt[e] ){
            ll v = to[e] ;
            if ( dis[v] > d + cost[e] ){
                dis[v] = d + cost[e] ;
                pq.push( make_pair(-dis[v] , v) ) ;
            }
        }

    }

}

const ll N = 500 + 5;

ll grid[N][N],n,m,a,b;
ll vis[N][N];



ll valid(ll i,ll j){
    return i >= 0 && j >= 0 && i < n && j < m;
}

void mark(ll i,ll j,ll p){
    if(!valid(i,j))  
        return;
    if(vis[i][j])  return;
    vis[i][j] = 1;

    if(!grid[i][j]){
        grid[i][j] = 1e9;
        return;
    }
        
    grid[i][j] = (p ? a : b);
    
    mark(i + 1,j,!p);
    mark(i - 1,j,!p);
    mark(i,j + 1,!p);
    mark(i,j - 1,!p);
}





int main(void){

    #ifdef Khaled
        freopen("in.txt","r",stdin);
        //freopen("out.txt","w",stdout);
    #endif
    fast;
    cin >> m >> n >> a >> b;
    for(ll i = 0;i<n;i++){
        for(ll j = 0;j<m;j++){
            char c;
            cin >> c;
            grid[i][j] = (c =='.');
        }
    }
    mark(0,0,1);
    grid[0][0] = 0;
    nn = n * m;
    init();

    ll di[] = {1,0,-1,0};
    ll dj[] = {0,1,0,-1};
    for(ll i = 0;i<n;i++){
        for(ll j = 0;j<m;j++){
            for(ll k = 0;k<4;k++){
                ll ii = i + di[k];
                ll jj = j + dj[k];
                if(valid(i,j) && valid(ii,jj) && grid[i][j] < 1e4 && grid[ii][jj] < 1e4){
                    addEdge(i * m + j,ii * m + jj,grid[ii][jj]);
                }
            }
        }
    }
    ShortestPath(0);
    if(dis[n * m - 1] >= 1e9){
        cout << "IMPOSSIBLE\n";
    }
    else{
        cout << dis[n * m - 1] << endl;
    }
    


}