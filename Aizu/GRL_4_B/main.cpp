
#include <bits/stdc++.h>

#define all(a) a.begin(),a.end()
#define fast cin.tie(0),ios::sync_with_stdio(0),cout.tie(0)
#define ll long long 
#define ull unsigned long long 

using namespace std;



const int N = 1e4 + 5,M = 1e5 + 5;

int head[N],nxt[M],to[M],n,m,ne;	

int vis[N],vid,res[N],resSz;
int inDeg[N];

void init(){
	ne = 0;
	memset(head,-1,N * sizeof(head[0]));
}


void addEdge(int u,int v){
	nxt[ne] = head[u];
	to[ne] = v;
	head[u] = ne++;
	inDeg[v]++;
}

void addBiEdge(int u,int v){
	addEdge(u,v);
	addEdge(v,u);
}


void topo(){
	priority_queue<int>pq;
	for(int u = 0;u<n;u++){
		if(!inDeg[u])
			pq.push(-u);
	}
	while(pq.size()){
		int u = - pq.top();
		pq.pop();
		cout << u << endl;
		for(int e = head[u];~e;e = nxt[e]){
			int v = to[e];
			if(!--inDeg[v])
				pq.push(-v);
		}
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
		addEdge(u,v);
	}

	topo();

}	
