#include <bits/stdc++.h>
#define fast cin.tie(0),ios::sync_with_stdio(0),cout.tie();
#define all(a) a.begin(),a.end()

typedef long long ll;
typedef unsigned long long ull;

using namespace std;

const int N = 1e5 + 5,M = 1e5 + 5;

int n;

struct ADJ{
	int head[N],to[M],nxt[M],n,ne;
	int inDeg[N];

	void init(int x){
		n = x;
		memset(head,-1,(n + 1) * sizeof head[0]);
		memset(inDeg,0,(n + 1) * sizeof inDeg[0]);
		ne = 0;
	}

	void addEdge(int u,int v){
		nxt[ne] = head[u];
		to[ne] = v;
		head[u] = ne++;
		inDeg[v]++;
	}
	void addBiEdge(int u,int v){
		addEdge(u,v);
		addEdge(v,u);
	}


}adj,rev_adj,DAG;

int vis[N],vid;
int C[N],ncp;

int stk[N],stkSz;

void dfs1(int u){
	
	vis[u] = vid;
	for(int e = adj.head[u];~e;e = adj.nxt[e]){
		int v = adj.to[e];
		if(vis[v] == vid)
			continue;
		dfs1(v);
	}
	stk[stkSz++] = u; 
}

void dfs2(int u,int cid){
	vis[u] = vid;
	C[u] = cid;
	for(int e = rev_adj.head[u];~e;e = rev_adj.nxt[e]){
		int v = rev_adj.to[e];
		if(vis[v] == vid)
			continue;
		dfs2(v,cid);
	}

}

void K(){


	vid++;
	stkSz = 0;

	for(int u = 0;u < n;u++){
		if(vis[u] != vid)
			dfs1(u);
	}

	vid++;
	ncp = 0;
	for(int i = n - 1;i >= 0;i--){
		int u = stk[i];
		if(vis[u] != vid){
			dfs2(u,ncp++);
		}
	}

	DAG.init(ncp);
	for(int u = 0;u < n;u++){
		for(int e = adj.head[u];~e;e = adj.nxt[e]){
			int v = adj.to[e];
			if(C[u] == C[v])
				continue;
			DAG.addEdge(C[u],C[v]);
		}
	}


}


signed main(void){

	#ifdef Khaled
		freopen("in.txt","r",stdin);
		//freopen("out.txt","w",stdout);
	#endif
	#ifndef Khaled
		#define endl '\n'
		fast;
	#endif
	
	int cs = 1;
	int t;
	cin >> t;
	while(t--){
		int m;
		cin >> n >> m;
		adj.init(n);
		rev_adj.init(n);
		while(m--){
			int u,v;
			cin >> u >> v;
			u--,v--;
			adj.addEdge(u,v);
			rev_adj.addEdge(v,u);
		}
		K();
		cout << "Case " << cs++ << ": ";
		cout <<  count(DAG.inDeg,DAG.inDeg + ncp,0) << endl;
	}



}


