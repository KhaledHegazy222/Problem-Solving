
#include <bits/stdc++.h>

#define all(a) a.begin(),a.end()
#define fast cin.tie(0),ios::sync_with_stdio(0),cout.tie(0)
#define ll long long 
#define ull unsigned long long 

using namespace std;

const int N = 1e5 + 5,M = 3e5 + 5,MOD = 1e9 + 7;

int vis[N],compID[N],cost[N],vid,ncp,n,m;
int res[N],frq[N];

stack<int>stk;

struct ADJ{

	int head[N],nxt[M],to[M],ne;


	void init(int n){
		memset(head,-1,n * sizeof(head[0]));
		ne =  0;
	}


	void addEdge(int u,int v){
		nxt[ne] = head[u];
		to[ne] = v;
		head[u] = ne++;
	}



}adj,radj,Cgraph;




void dfs1(int u){
	vis[u] = vid;

	for(int e = adj.head[u];~e;e = adj.nxt[e]){
		int v = adj.to[e];
		if(vis[v] != vid)
			dfs1(v);
	}
	stk.push(u);

}


void dfs2(int u,int cid){
	vis[u] = vid;
	compID[u] = cid;
	for(int e = radj.head[u];~e;e = radj.nxt[e]){
		int v = radj.to[e];
		if(vis[v] != vid)
			dfs2(v,cid);
	}
}


void K(){
	vid++;
	for(int u = 0;u<n;u++){
		if(vis[u] != vid)
			dfs1(u);
	}

	vid++;
	ncp = 0;
	while(stk.size()){
		int u = stk.top();
		stk.pop();
		if(vis[u] != vid)
			dfs2(u,ncp++);
	}

	Cgraph.init(ncp);
	fill(res,res + ncp,INT_MAX);

	for(int u = 0;u<n;u++){
		res[compID[u]] = min(res[compID[u]],cost[u]);
	}
	for(int u = 0;u<n;u++){
		frq[compID[u]] += (cost[u] == res[compID[u]]);
	}

}





int main(void){	
	//fast;
	#ifdef Khaled
		freopen("in.txt","r",stdin);
		//freopen("out.txt","w",stdout);
	#endif
	cin >> n;

	adj.init(n);
	radj.init(n);
	for(int i = 0;i<n;i++){
		cin >> cost[i];
	}
	cin >> m;
	while(m--){
		int u,v;
		cin >> u >> v;
		u--,v--;
		adj.addEdge(u,v);
		radj.addEdge(v,u);
	}

	K();

	ll sum = 0;
	ll mul = 1;
	for(int i = 0;i<ncp;i++){
		sum += res[i];
		mul = (mul * frq[i]) % MOD;
	}
	cout << sum << " " << mul << endl;
}	