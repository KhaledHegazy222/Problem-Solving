
#include <bits/stdc++.h>

#define all(a) a.begin(),a.end()
#define fast cin.tie(0),ios::sync_with_stdio(0),cout.tie(0)
#define ll long long 
#define ull unsigned long long 

using namespace std;



const int N = 1e4 + 5,M = 5e5 + 5;

int head[N],nxt[M],to[M],n,m,ne;	

int vis[N],vid;
int color[N];

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


bool dfs(int u,int c){
	color[u] = c;
	vis[u] = vid;
	bool res = true;
	for(int e = head[u];~e;e = nxt[e]){
		int v = to[e];
		if(vis[v] != vid)
			res &= dfs(v,c ^ 3);
		else if(color[v] == c)
			return 0;
	}
	return res;
}




int main(void){	
	fast;
	#ifdef Khaled
		freopen("in.txt","r",stdin);
		//freopen("out.txt","w",stdout);
	#endif
	while(cin >> n){
		if(!n)
			return 0;
		cin >> m;
		init();
		for(int i = 0;i<m;i++){
			int u,v;
			cin >> u >> v;
			u--,v--;
			addBiEdge(u,v);
		}
		vid++;
		cout << (dfs(0,1) ? "BICOLOURABLE.\n" : "NOT BICOLOURABLE.\n");

	}

}	
