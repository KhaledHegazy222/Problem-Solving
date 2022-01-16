
#include <bits/stdc++.h>

#define all(a) a.begin(),a.end()
#define fast cin.tie(0),ios::sync_with_stdio(0),cout.tie(0)
#define ll long long 
#define ull unsigned long long 

using namespace std;



const int N = 1e4 + 5,M = 5e5 + 5;

int vis[N],vid,n,m;
int compID[N],ncp;
stack<int>stk;

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
}adj,radj;


void dfs1(int u){
	vis[u] = vid;
	for(int e = adj.head[u];~e;e = adj.nxt[e]){
		int v = adj.to[e];
		if(vis[v] == vid) continue;
		dfs1(v);
	}
	stk.push(u);
}

void dfs2(int u,int cid){
	vis[u] = vid;
	compID[u] = cid;
	for(int e = radj.head[u];~e;e = radj.nxt[e]){
		int v = radj.to[e];
		if(vis[v] == vid) continue;
		dfs2(v,cid);
	}
}


void K(){
	vid++;
	for(int u = 0;u < n;u++){
		if(vis[u] != vid)
			dfs1(u);
	}
	vid++;
	while(stk.size()){
		int u = stk.top();
		stk.pop();
		if(vis[u] != vid)
			dfs2(u,ncp++);
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
	radj.init(n);
	for(int i = 0;i<m;i++){
		int u,v;
		cin >> u >> v;
		u--,v--;
		adj.addEdge(u,v);
		radj.addEdge(v,u);
	}
	K();
	cout << ncp << endl;


}	
