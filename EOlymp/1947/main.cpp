
#include <bits/stdc++.h>

#define all(a) a.begin(),a.end()
#define fast cin.tie(0),ios::sync_with_stdio(0),cout.tie(0)
#define ll long long 
#define ull unsigned long long 

using namespace std;



const int N = 2e4 + 5,M = 4e5 + 5;

int vis[N],vid,n,m;

int dfsTime[N],low[N],curTime;
int compID[N],ncp;
int res;
stack<int>stk;

map<pair<int,int>,int>edges;
struct ADJ{

	int head[N],nxt[M],to[M],ne;	
	void init(int n){
		ne = 0;
		memset(head,-1,n * sizeof(head[0]));
	}

	void addEdge(int u,int v){
		nxt[ne] = head[u];
		to[ne] = v;
		head[u] = ne++;
	}

	void addBiEdge(int u,int v){
		addEdge(u,v);
		addEdge(v,u);
	}

}adj,dag;



void dfsTargan(int u){
	vis[u] = vid;
	compID[u] = -1;
	dfsTime[u] = low[u] = curTime++;
	stk.push(u);
	for(int e = adj.head[u];~e;e = adj.nxt[e]){
		int v = adj.to[e];
		if(vis[v] != vid){
			dfsTargan(v);
			low[u] = min(low[u],low[v]);
		}
		else if(compID[v] == -1)
			low[u] = min(low[u],dfsTime[v]);
	}
	if(dfsTime[u] == low[u]){
		while(stk.top() != u){
			compID[stk.top()] = ncp;
			stk.pop();
		}
		stk.pop();
		compID[u] = ncp++;
	} 
}

void T(){
	vid++;
	curTime = ncp = res = 0;
	for(int u = 0;u < n;u++){
		if(vis[u] != vid)
			dfsTargan(u);
	}
	dag.init(ncp);
	for(int u = 0;u<n;u++){
		for(int e = adj.head[u];~e;e = adj.nxt[e]){
			int v = adj.to[e];
			if(compID[u] == compID[v]) continue;
			dag.addEdge(compID[u],compID[v]),edges[{compID[u],compID[v]}]++;
		}
	}
}







int main(void){	
	
	fast;
	#ifdef Khaled
		freopen("in.txt","r",stdin);
		//freopen("out.txt","w",stdout);
	#endif
	cin >> n >> m;
	adj.init(n);
	for(int i = 0;i<m;i++){
		int u,v;
		cin >> u >> v;
		u--,v--;
		adj.addEdge(u,v);
	}

	T();
	cout << edges.size() << endl;
}