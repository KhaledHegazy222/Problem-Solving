
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
int isArt[N];


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


int dfs(int u,int par){
	vis[u] = vid;
	int children = 0;
	low[u] = dfsTime[u] = curTime++;
	for(int e = head[u];~e;e = nxt[e]){
		int v = to[e];
		if(v == par) continue;
		if(vis[v] != vid){
			children++;
			dfs(v,u);
			low[u] = min(low[u],low[v]);
			if(dfsTime[u] <= low[v])
				isArt[u] = vid;
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
	for(int u = 0;u<n;u++){
		if(vis[u] != vid) 
			isArt[u] = dfs(u,-1) > 1 ? vid : 0;
	}
}


int main(void){	
	
	//fast;
	#ifdef Khaled
		freopen("in.txt","r",stdin);
		//freopen("out.txt","w",stdout);
	#endif
	int cs = 1;
	while(cin >> n){
		if(!n) return 0;

		init();
		map<int,string>itn;
		map<string,int>nti;
		for(int i = 0;i<n;i++){
			string s;
			cin >> s;
			nti.insert({s,i});
			itn.insert({i,s});
		}
		cin >> m;
		for(int i = 0;i<m;i++){
			string u,v;
			cin >> u >> v;
			addBiEdge(nti[u],nti[v]);
		}
		T();
		int cnt = 0;
		vector<string>res;
		for(int u = 0;u<n;u++){
			if(isArt[u] == vid)
				cnt++,res.push_back(itn[u]);
		}
		if(cs - 1)
			cout << endl;
		cout << "City map #" << cs++ << ": " << cnt << " camera(s) found\n";
		sort(all(res));
		for(auto it : res)
			cout << it << endl;
	}	

	




}