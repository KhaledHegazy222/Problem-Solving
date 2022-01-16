
#include <bits/stdc++.h>

#define all(a) a.begin(),a.end()
#define fast cin.tie(0),ios::sync_with_stdio(0),cout.tie(0)
#define ll long long 
#define ull unsigned long long 

using namespace std;



const int N = 1e3 + 5,M = N * N;

int n;
int vis[N],vid,compID[N],ncp;
stack<int>stk;



struct ADJ{
	int head[N],nxt[M],to[M],m,ne;	
		
	void init(int n){
		ne = 0;
		memset(head,-1,N * sizeof(head[0]));
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



}adj,radj;








void dfs1(int u){
	vis[u] = vid;
	for(int e = adj.head[u];~e;e = adj.nxt[e]){
		int v = adj.to[e];
		if(vis[v] == vid) continue;
		dfs1(v);
	}
	stk.push(u);
}
void dfs2(int u,int cid){
	vis[u] = vid;
	compID[u] = cid;
	for(int e = radj.head[u];~e;e = radj.nxt[e]){
		int v = radj.to[e];
		if(vis[v] == vid) continue;
		dfs2(v,cid);
	}
}




int K(){
	vid++;
	for(int u = 0;u<n;u++){
		if(vis[u] != vid)
			dfs1(u);
	}
	vid++;
	while(stk.size()){
		int v = stk.top();
		stk.pop();
		if(vis[v] != vid)
			dfs2(v,ncp++);
	}
	return ncp != n;
}


int main(void){	
	fast;
	#ifdef Khaled
		freopen("in.txt","r",stdin);
		//freopen("out.txt","w",stdout);
	#endif


	cin >> n;
	adj.init(n);
	radj.init(n);
	for(int i = 0;i<n;i++){
		for(int j = 0;j<n;j++){
			int x;
			cin >> x;
			if(x)
				adj.addEdge(i,j),radj.addEdge(j,i);

		}
	}
	cout << K() << endl;


}	
