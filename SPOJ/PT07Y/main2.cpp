
#include <bits/stdc++.h>

#define all(a) a.begin(),a.end()
#define fast cin.tie(0),ios::sync_with_stdio(0),cout.tie(0)
#define ll long long 
#define ull unsigned long long 

using namespace std;
const int N = 1e4 + 5,M = 2e4 + 5;
int head[N],to[M],nxt[M],n,m,ne;


int vis[N],vid;

int dfs(int u){
	vis[u] = vid;
	int res = 0;
	for(int e = head[u];~e;e = nxt[e]){
		int v = to[e];
		if(vis[v] != vid)
			res += dfs(v);
	}
	return res + 1;
}


void init(){
	memset(head,-1,n * sizeof(head[0]));
	ne = 0;
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





int main(void){	
	//fast;
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
	++vid;
	if(m == n - 1 && dfs(0) == n)
		cout << "YES\n";
	else
		cout << "NO\n";



}	