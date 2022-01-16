
#include <bits/stdc++.h>

#define all(a) a.begin(),a.end()
#define fast cin.tie(0),ios::sync_with_stdio(0),cout.tie(0)
#define ll long long

using namespace std;

const int N = 1e4 + 5,M = 1e6 + 5;

int head[N],nxt[M],to[M],n,m,ne;
int vis[N],vid;

int dfsTime[N],low[N],curTime;
int isArt[N];

void init(){
	ne = 0;
	memset(head,-1,(n + 1) * sizeof head[0]);
	memset(isArt,0,(n + 1) * sizeof isArt[0]);
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
	for(int u = 0;u<n;u++)
		if(vis[u] != vid)
			isArt[u] = dfs(u,u) > 1;
}







int main(void){

	#ifdef Khaled
		freopen("in.txt","r",stdin);
		freopen("out.txt","w",stdout);

    #endif
	while(cin >> n){
		if(!n) return 0;
		init();
		while(1){
			int u;
			cin >> u;
			if(!u) break;
			u--;
			string str;
			getline(cin,str);
			stringstream ss(str);
			int v;
			while(ss >> v){
				v--;
				addBiEdge(u,v);
			}
		}
		T();
		int cnt = 0;
		for(int i = 0;i<n;i++){
			cnt += isArt[i];
		}
		cout << cnt << endl;;

	}

}
