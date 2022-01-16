
#include <bits/stdc++.h>

#define all(a) a.begin(),a.end()
#define fast cin.tie(0),ios::sync_with_stdio(0),cout.tie(0)
#define ll long long 
#define ull unsigned long long 

using namespace std;



const int N = 1e5 + 5,M = 2e5 + 5;
int head[N],to[M],nxt[M],n,m,ne;
int vis[N],vid;

int dfsTime[N],low[N],curTime;

vector<pair<int,int>>bridges;


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

int dfsTragan(int u,int par){
	int children = 0;

	dfsTime[u] = low[u] = ++curTime;

	for(int e = head[u];~e;e = nxt[e]){
		int v = to[e];
		if(v == par) continue;
		if(!dfsTime[v]){
			children++;
			dfsTragan(v,u);
			if(dfsTime[u] < low[v])
				bridges.push_back({min(u,v),max(u,v)});
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
	bridges.clear();
	for(int u = 0;u < n;u++){
		if(!dfsTime[u]){
			dfsTragan(u,-1);
		}
	}
	
	


}


int main(void){	
	
	//fast;
	#ifdef Khaled
		freopen("in.txt","r",stdin);
		//freopen("out.txt","w",stdout);
	#endif
	

	while(cin >> n){
		init();
		for(int i = 0;i<n;i++){
			int u;
			cin >> u;
			int x;
			scanf(" (%d) ",&x);
			while(x--){
				int v;
				cin >> v;
				addBiEdge(u,v);
			}
		}
		T();
		cout << bridges.size() << " critical links\n";
		sort(all(bridges));
		for(auto it : bridges){
			cout << it.first << " - " << it.second << endl;
		}
		cout << endl;
	}


}