
#include <bits/stdc++.h>

#define all(a) a.begin(),a.end()
#define fast cin.tie(0),ios::sync_with_stdio(0),cout.tie(0)
#define ll long long 
#define ull unsigned long long 

using namespace std;



const int N = 100,M = 1e4 + 5;
int head[N],to[M],nxt[M],n,m,ne;
int vis[N],vid;

int dfsTime[N],low[N],curTime;
int compID[N],ncp;
stack<int>stk;

void init(){
	ne = 0;
	memset(head,-1,n * sizeof head[0]);
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


void dfs(int u){
	vis[u] = vid;
	dfsTime[u] = low[u] = curTime++;
	compID[u] = -1;
	stk.push(u);
	for(int e = head[u];~e;e = nxt[e]){
		int v = to[e];
		if(vis[v] != vid){
			dfs(v);
			low[u] = min(low[u],low[v]);
		}
		else if(compID[v] == -1){
			low[u] = min(low[u],dfsTime[v]);
		}
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
	vid++;
	curTime = 0;
	ncp = 0;
	for(int u = 0;u<n;u++){
		if(vis[u] != vid)
			dfs(u);
	}
}


int main(void){	
	
	//fast;
	#ifdef Khaled
		freopen("in.txt","r",stdin);
		//freopen("out.txt","w",stdout);
	#endif
	

	int t;
	cin >> t;
	while(t--){
		cin >> n;
		init();
		for(int i = 0;i<n;i++){
			for(int j = 0;j<n;j++){
				char dummy;
				cin >> dummy;
				if(dummy == 'Y')
					addEdge(i,j);
			}
		}
		T();
		cout << ncp << endl;
	}




}