
#include <bits/stdc++.h>

#define all(a) a.begin(),a.end()
#define fast cin.tie(0),ios::sync_with_stdio(0),cout.tie(0)
#define ll long long 
#define ull unsigned long long 

using namespace std;

const int N = 1e4 + 5,M = 1e5 + 5;



int head[N],nxt[M],to[M],n,m,ne;


void init(){
	memset(head,-1,n * sizeof(head[0]));
	ne =  0;
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


int vis[N],vid;
int dfsTime[N],low[N],isArt[N],curTime;


int dfsTragan(int u,int par){
	int children = 0;

	dfsTime[u] = low[u] = ++curTime;

	for(int e = head[u];~e;e = nxt[e]){
		int v = to[e];
		if(v == par) continue;
		if(!dfsTime[v]){
			children++;
			dfsTragan(v,u);
			if(dfsTime[u] <= low[v])
				isArt[u] = 1;
			low[u] = min(low[u],low[v]);
		}
		else{
			low[u] = min(low[u],dfsTime[v]);
		}
	}
	return children;
}


void T(){
	curTime = 0;
	memset(low,0,n * sizeof(low[0]));
	memset(dfsTime,0,n * sizeof(dfsTime[0]));
	memset(isArt,0,n * sizeof(isArt[0]));
	for(int u = 0;u < n;u++){
		if(!dfsTime[u]){
			isArt[u] = dfsTragan(u,-1) > 1;
		}
	}
	


}




int main(void){	
	fast;
	#ifdef Khaled
		freopen("in.txt","r",stdin);
		//freopen("out.txt","w",stdout);
	#endif

	while(cin >> n >> m){
		if(!n && !m) return 0;

		init();

		while(m--){
			int u,v;
			cin >> u >> v;
			u--,v--;
			addBiEdge(u,v);
		}
		T();
		int cnt = 0;
		for(int i = 0;i<n;i++){
			cnt += isArt[i];
		}
		cout << cnt << endl;
	}


}	