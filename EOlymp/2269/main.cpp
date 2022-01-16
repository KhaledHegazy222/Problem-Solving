
#include <bits/stdc++.h>

#define all(a) a.begin(),a.end()
#define fast cin.tie(0),ios::sync_with_stdio(0),cout.tie(0)
#define ll long long 
#define ull unsigned long long 

using namespace std;
const int N = 1e4 + 5,M = 2e4 + 5;
int head[N],to[M],nxt[M],n,m,ne;


int vis[N],vid;



void dfs(int u){
	vis[u] = vid;
	for(int e = head[u];~e;e = nxt[e]){
		int v = to[e];
		if(vis[v] != vid)
			dfs(v);
	}
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

	cin >> n;
	init();
	for(int i = 0;i<n;i++){
		for(int j = 0;j<n;j++){
			int x;
			cin >> x;
			if(x)
				addEdge(i,j);
		}
	}
	++vid;
	int cc = 0;
	for(int i = 0;i<n;i++){
		if(vis[i] != vid)
			dfs(i),cc++;
	}
	cout << cc << endl;
	


}	