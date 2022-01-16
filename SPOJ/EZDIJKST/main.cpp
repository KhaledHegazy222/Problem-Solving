
#include <bits/stdc++.h>

#define all(a) a.begin(),a.end()
#define fast cin.tie(0),ios::sync_with_stdio(0),cout.tie(0)
#define ll long long 
#define ull unsigned long long 

using namespace std;

const int N = 1e4 + 5,M = 2 * N;



int head[N],nxt[M],to[M],n,m,ne;

int dist[N],cost[M];


void init(){
	memset(head,-1,n * sizeof(head[0]));
	ne =  0;
}


void addEdge(int u,int v,int cst){
	nxt[ne] = head[u];
	to[ne] = v;
	cost[ne] = cst;
	head[u] = ne++;
}



void dijistra(int src){
	
	memset(dist,0x3f,n * sizeof(dist[0]) );
	priority_queue<pair<int,int>>pq;
	dist[src] = 0;

	pq.push({0,src});
	while(pq.size()){
		int d = -pq.top().first;
		int u = pq.top().second;
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
	fast;
	#ifdef Khaled
		freopen("in.txt","r",stdin);
		//freopen("out.txt","w",stdout);
	#endif

	int t;
	cin >> t;
	while(t--){
		cin >> n >> m; 
		init();
		for(int i = 0;i<m;i++){
			int u,v,cst;
			cin >> u >> v >> cst;
			u--,v--;
			addEdge(u,v,cst);
		}

		int st,en;
		cin >> st >> en;
		st--,en--;
		dijistra(st);
		if(dist[en] == 0x3f3f3f3f )
			cout << "NO\n";
		else
			cout << dist[en] << endl;

	}

}	