#include <bits/stdc++.h>

using namespace std;

const int N = 50 *  50 + 5,M = N *4;

int w,h;

int dfsTime[N],low[N],isArt[N],curTime;
int vis[N],vid;

struct ADJ{
	int head[N],nxt[M],to[M],n,m,ne;
	void init(int n){
		this->n = n;
		ne = 0;
		memset(head,-1,(n + 1) * sizeof head[0]);
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

}adj;

int dfs(int u){
	int children = 0;
	vis[u] = vid;
	dfsTime[u] = low[u] = curTime++;
	isArt[u] = 0;
	for(int e = adj.head[u];~e;e = adj.nxt[e]){
		int v = adj.to[e];
		if(vis[v] != vid){
			children++;
			dfs(v);
			low[u] = min(low[u],low[v]);
			if(low[v] >= dfsTime[u])
				isArt[u] = 1;
		}
		else{
			low[u] = min(low[u],dfsTime[v]);
		}
	}
	return children;
}


void T(){
	
	curTime = 0;
	vid++;
	for(int u = 0;u < adj.n;u++){
		if(vis[u] != vid)
			isArt[u] = dfs(u) > 1;
	}
	
}


int valid(int i,int j){
	return i >= 0 && i < w && j >= 0 && j < h;
	
}

int main(void){
	//freopen("in.txt","r",stdin);
	cin >> w >> h;
	int grid[w][h];
	int nodeCnt = 0;
	map<pair<int,int>,int>comp;
	for(int i = 0;i<w;i++){
		for(int j = 0;j<h;j++){
			char c;
			cin >> c;
			grid[i][j] = (c == '#');
			if(grid[i][j]){
				comp.insert({{i,j},nodeCnt++});
			}
		}	
	}
	adj.init(nodeCnt);
	if(nodeCnt < 3)
		return puts("-1") * 0;
	
	for(int i = 0;i<w;i++){
		for(int j = 0;j<h;j++){
			if(!grid[i][j]) continue;
			if(valid(i+1,j) && grid[i+1][j]) adj.addEdge(comp[{i,j}],comp[{i+1,j}]);
			if(valid(i-1,j) && grid[i-1][j]) adj.addEdge(comp[{i,j}],comp[{i-1,j}]);
			if(valid(i,j+1) && grid[i][j+1]) adj.addEdge(comp[{i,j}],comp[{i,j+1}]);
			if(valid(i,j-1) && grid[i][j-1]) adj.addEdge(comp[{i,j}],comp[{i,j-1}]);
		}
	}
	
	T();
	for(int i = 0;i<adj.n;i++){
			if(isArt[i])
				return puts("1") * 0;
	}
	puts("2");
	
	
	
}