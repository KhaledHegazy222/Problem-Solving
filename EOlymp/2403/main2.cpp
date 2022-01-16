
#include <bits/stdc++.h>

#define all(a) a.begin(),a.end()
#define fast cin.tie(0),ios::sync_with_stdio(0),cout.tie(0)
#define ll long long 
#define ull unsigned long long 

using namespace std;



const int N = 1e4 + 5,M = 5e5 + 5;

int vis[N],vid,n,m;
int compID[N],ncp;
int dfsTime[N],low[N],curTime;
stack<int>stk;


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


void targanDFS(int u){
	vis[u] = vid;
	compID[u] = -1;
	low[u] = dfsTime[u] = curTime++;
	stk.push(u);
	for(int e = head[u];~e;e = nxt[e]){
		int v = to[e];
		if(vis[v] != vid){
			targanDFS(v);
			low[u] = min(low[u],low[v]);
		}
		else if(compID[v] == -1)
			low[u] = min(low[u],low[v]);

	}

	if(low[u] == dfsTime[u]){
		while(stk.top() != u){
			compID[stk.top()] = ncp;
			stk.pop();
		}
		compID[u] = ncp++;
		stk.pop();
	}


}

void T(){
	ncp = 0;
	curTime = 0;
	vid++;
	for(int u = 0;u < n;u++){
		if(vis[u] != vid)
			targanDFS(u);
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
		addEdge(u,v);
	}
	T();


	cout << ncp << endl;


}	
