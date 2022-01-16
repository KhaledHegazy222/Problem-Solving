#include <iostream>
#include <cstring>
#include <algorithm>
#define all(a) a.begin(),a.end()
#define fast cin.tie(0),ios::sync_with_stdio(0),cout.tie(0)
#define ll long long 
#define ull unsigned long long 

using namespace std;

const int N = 1e5,M = 1e5;
int n,m;


struct ADJ{
	int head[N],nxt[M],to[M],ne;
	void init(int n){
		ne = 0;
		memset(head,-1,n * sizeof head[0]);
	}


	void addEdge(int u,int v){
		nxt[ne] = head[u];
		to[ne] = v;
		head[u] = ne++;
	}



}adj,radj,cgraph;


int stk[N],stkSz,vis[N],vid,compID[N],ncp;
int notSnk[N],notSrc[N];
void dfs1(int u){
	vis[u] = vid;
	for(int e = adj.head[u];~e;e = adj.nxt[e]){
		int v = adj.to[e];

		if(vis[v] == vid) continue;
		dfs1(v);
	}


	stk[stkSz++] = u;

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


void k(){
	++vid;
	for(int i = 0;i<n;i++){
		if(vis[i] != vid)
			dfs1(i);
	}

	++vid;
	ncp = 0;
	for(int i = n - 1;i>=0;i--){
		if(vis[stk[i]] != vid)
			dfs2(stk[i],ncp++);
	}
	cgraph.init(ncp);
	for(int u = 0;u<n;u++){
		for(int e = adj.head[u];~e;e = adj.nxt[e]){
			int v = adj.to[e];
			if(compID[v] != compID[u]){
				cgraph.addEdge(compID[u],compID[v]);

				notSnk[compID[u]] = vid;
				notSrc[compID[v]] = vid;
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

	cin >> n;
	adj.init(n);
	radj.init(n);
	
	for(int i = 0;i<n;i++){
		int v;
		while(cin >> v){
			if(!v)
				break;
			v--;
			adj.addEdge(i,v);
			radj.addEdge(v,i);
		}
	}

	k();
	
	int cntSrc = 0,cntSnk = 0;
	for(int i = 0;i<ncp;i++){
		cntSrc += (notSrc[i] != vid);
		cntSnk += (notSnk[i] != vid);
	}
	cout << cntSrc << "\n" << (ncp == 1 ? 0 : max(cntSnk,cntSrc)) << endl;


}	