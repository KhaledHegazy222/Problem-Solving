
#include <bits/stdc++.h>

#define all(a) a.begin(),a.end()
#define fast cin.tie(0),ios::sync_with_stdio(0),cout.tie(0)
#define ll long long 
#define ull unsigned long long 

using namespace std;



const int N = 2e4 + 5,M = 4e5 + 5;

int vis[N],vid,n,m;
int dfsTime[N],low[N],curTime;
int isArt[N];

int head[N],nxt[M],to[M],ne;	


void init(){
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



int dfs(int u,int par){
	int children = 0;
	vis[u] = vid;
	dfsTime[u] = low[u] = curTime++;
	for(int e = head[u];~e;e = nxt[e]){
		int v = to[e];
		if(v == par) continue;
		if(vis[v] != vid){
			children++,dfs(v,u);
			low[u] = min(low[u],low[v]);
			if(dfsTime[u] <= low[v])
				isArt[u] = 1;
		}
		else
			low[u] = min(low[u],dfsTime[v]);
			
	}
	return children;
}


void T(){
	vid++;	
	curTime = 0;
	for(int u = 0;u<n;u++){
		if(vis[u] != vid)
			isArt[u] = dfs(u,-1) > 1;
	}
}

int main(void){	
	fast;
	#ifdef Khaled
		freopen("in.txt","r",stdin);
		//freopen("out.txt","w",stdout);
	#endif
	cin >> n >> m;
	init();
	for(int i = 0;i<m;i++){
		int u,v;
		cin >> u >> v;
		u--,v--;
		addBiEdge(u,v);
	}
	T();

	int cnt = 0;
	for(int u = 0;u < n;u++){
		cnt += isArt[u];
	}
	cout << cnt << endl;
	
	for(int u = 0;u < n;u++){
		if(isArt[u])
			cout << u + 1 << endl;
	}


}	