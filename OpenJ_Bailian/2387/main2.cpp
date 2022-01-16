
#include <bits/stdc++.h>

#define fast cin.tie(0),ios::sync_with_stdio(0),cout.tie(0)
#define all(a) a.begin(),a.end()
#define ll long long 
#define ull unsigned long long 

using namespace std;

const int N = 1e3 + 5,M = N * N;

int head[N],to[M],nxt[M],cost[M],ne;
int n,m;


int dist[N];


void init(){
	ne = 0;
	memset(head,-1,(n + 1) * sizeof head[0]);
}

void addEdge(int u,int v,int cst){
	nxt[ne] = head[u];
	to[ne] = v;
	cost[ne] = cst; 
	head[u] = ne++;

}

void addBiEdge(int u,int v,int cst){
	addEdge(u,v,cst);
	addEdge(v,u,cst);
}


void dijkstra(int src){
	memset(dist,0x3f,n * sizeof dist[0]);
	priority_queue<pair<int,int>>pq;
	dist[src] = 0;
	pq.push({0,src});
	while(pq.size()){
		int u = pq.top().second;
		pq.pop();
		for(int e = head[u];~e;e = nxt[e]){
			int v = to[e];
			int d = cost[e];
			if(dist[v] > d + dist[u]){
				dist[v] = d + dist[u];
				pq.push({dist[v],v});
			}
				
		}
	}

}

int main(void){	

	fast;
	#ifdef Khaled
		freopen("in.txt","r",stdin);
		//freopen("out.txt","w",stdout);
	#endif

	cin >> m >> n;
	init();
	while(m--){
		int u,v,c;
		cin >> u >> v >> c;
		addBiEdge(--u,--v,c);
	}
	dijkstra(0);
	cout << dist[n - 1] << '\n';
}	