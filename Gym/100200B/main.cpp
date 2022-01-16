
#include <bits/stdc++.h>

#define all(a) a.begin(),a.end()
#define fast cin.tie(0),ios::sync_with_stdio(0),cout.tie(0)
#define ll long long 
#define ull unsigned long long 

using namespace std;



const int N = 2e4 + 5,M = 4e5 + 5;

int vis[N],vid,n,m;
int dfsTime[N],low[N],curTime;

int head[N],nxt[M],to[M],ne;	

vector<pair<int,int>>bridges;
map<pair<int,int>,int>edges;
map<pair<int,int>,int>frq;

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
			if(dfsTime[u] < low[v] && frq[{min(u,v),max(u,v)}] == 1)
				bridges.push_back({min(u,v),max(u,v)});
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
			dfs(u,-1);
	}
}

int main(void){	
	fast;
	#ifdef Khaled
		freopen("in.txt","r",stdin);
		//freopen("out.txt","w",stdout);
	#endif
	
	freopen("bridges.in","r",stdin);
	freopen("bridges.out","w",stdout);
	cin >> n >> m;
	init();
	for(int i = 0;i<m;i++){
		int u,v;
		cin >> u >> v;
		u--,v--;
		addBiEdge(u,v);
		edges.insert({{min(u,v),max(u,v)},i + 1});
		frq[{min(u,v),max(u,v)}]++;
	}
	T();

	
	cout << bridges.size() << endl;
	vector<int>res;
	for(auto it : bridges){
		res.push_back(edges[it]); 
	}
	sort(all(res));
	for(auto it : res){
		cout << it << " ";
	}
	cout << endl;


}	