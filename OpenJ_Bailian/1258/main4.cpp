
#include <bits/stdc++.h>

#define fast cin.tie(0),ios::sync_with_stdio(0),cout.tie(0)
#define all(a) a.begin(),a.end()
#define ll long long 
#define ull unsigned long long 

using namespace std;

const int N = 1e3 + 5,M = N * N;

int head[N],to[M],nxt[M],cost[M],ne;
int n,m;


int dist[N],vis[N],vid;


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


int  prim(int src){
	int res = 0;
	memset(dist,0x3f,n * sizeof dist[0]);
	priority_queue<pair<int,int>>pq;
	dist[src] = 0;
	++vid;
	pq.push({0,src});
	while(pq.size()){
		int u = pq.top().second;
		int d = -pq.top().first;
		pq.pop();
		if(vis[u] == vid)
			continue;
		vis[u] = vid;
		res += d;
		for(int e = head[u];~e;e = nxt[e]){
			int v = to[e];
			if(dist[v] > cost[e] && vis[v] != vid){
				dist[v] = cost[e];
				pq.push({-dist[v],v});
			}
				
		}
	}
	return res;

}

int main(void){	

	fast;
	#ifdef Khaled
		freopen("in.txt","r",stdin);
		//freopen("out.txt","w",stdout);
	#endif

	while(cin >> n){
		init();
		for(int i = 0;i<n;i++){
			for(int j = 0;j<n;j++){
				int x;
				cin >> x;
				addEdge(i,j,x);;
			}
		}
		cout << prim(0) << endl;
	}
}	