
#include <bits/stdc++.h>

#define all(a) a.begin(),a.end()
#define fast cin.tie(0),ios::sync_with_stdio(0),cout.tie(0)
#define ll long long 
#define ull unsigned long long 

using namespace std;



const int N = 1e5 + 5,M = N - 1;


int head[N],nxt[M],to[M],n,m,ne;
int vis[N],vid;

multimap<int,int>nodes;





void init(){
	ne = 0;
	memset(head,-1,N * sizeof(head[0]));
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

void dfs(int u = 0,int depth = 0){
	nodes.insert({depth,u});
	vis[u] = vid;
	for(int e = head[u];~e;e = nxt[e]){
		int v = to[e];
		if(vis[v] == vid) continue;
		dfs(v,depth + 1);
	}
}


int main(void){	
	fast;
	#ifdef Khaled
		freopen("in.txt","r",stdin);
		//freopen("out.txt","w",stdout);
	#endif


	cin >> n;
	init();
	for(int i = 0;i<n - 1;i++){
		int u,v;
		cin >> u >> v;
		u--,v--;
		addBiEdge(u,v);
	}
	vid++;
	dfs();
	int u = nodes.rbegin()->second;
	vid++;
	dfs(u);
	cout << nodes.rbegin()->first << endl;



}	
