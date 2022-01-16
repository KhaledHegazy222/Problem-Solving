
#include <bits/stdc++.h>

#define all(a) a.begin(),a.end()
#define fast cin.tie(0),ios::sync_with_stdio(0),cout.tie(0)
#define ll long long 

using namespace std;

const int N = 1e5 + 5,M = 2e5 + 5;

int head[N],nxt[M],to[M],n,m,ne;
int vis[N],vid;

int cost[M],dist[N];

void init(){
	ne = 0;
	memset(head,-1,(n + 1) * sizeof head[0]);
}

void addEdge(int u,int v,int c){
	nxt[ne] = head[u];
	cost[ne] = c;
	to[ne] = v;
	head[u] = ne++; 
}

void addBiEdge(int u,int v,int c){
	addEdge(u,v,c);
	addEdge(v,u,c);
}


void dijkstra(int src){
	priority_queue<pair<int,int>>pq;
	memset(dist,0x3f,(n + 1) * sizeof dist[0]);
	dist[src] = 0;
	pq.push({0,src});
	while(pq.size()){
		int u = pq.top().second;
		int d = -pq.top().first;
		pq.pop();
		for(int e = head[u];~e;e = nxt[e]){
			int v = to[e];
			if(d + cost[e] < dist[v]){
				dist[v] = d + cost[e];
				pq.push({-dist[v],v});
			}
		}
	}
	
}

int main(void){
    
	#ifdef Khaled
		freopen("in.txt","r",stdin);
		//freopen("out.txt","w",stdout);
	
    #endif
	int t;
	cin >> t;
	while(t--){
		int st,en;
		cin >> n >> m >> st >> en;
		st--,en--;
		init();
		for(int i = 0;i<m;i++){
			int a,b,c;
			cin >> a >> b >> c;
			--a,--b;
			addBiEdge(a,b,c);
		}
		dijkstra(st);
		if(dist[en] == 0x3f3f3f3f)
			cout << "NONE\n";
		else
			cout << dist[en] << endl;
	}	
	
}