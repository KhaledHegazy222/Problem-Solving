
#include <bits/stdc++.h>

#define fast cin.tie(0),ios::sync_with_stdio(0),cout.tie(0)
#define all(a) a.begin(),a.end()
#define ll long long 
#define ull unsigned long long 

using namespace std;

const int N = 1e3 + 5,M = N * N;

int head[N],to[M],nxt[M],cost[M],ne;
int n,m;


int dist[N],inQue[N],vid;


void init(){
	ne = 0;
	memset(head,-1,(n + 1) * sizeof head[0]);
}

void addEdge(int u,int v,int cst){
	nxt[ne] = head[u];
	to[ne] = v;
	cost[ne] = cst; 
	head[u] = ne++;

}

void addBiEdge(int u,int v,int cst){
	addEdge(u,v,cst);
	addEdge(v,u,cst);
}

int bellman(int src){
	memset(dist,0x3f,n * sizeof dist[0]);
	queue<int>q;
	int cnt = n;
	dist[src] = 0;
	inQue[src] = ++vid;
	q.push(src);
	while(cnt-- && q.size()){
		int s = q.size();
		while(s--){
			int u = q.front();
			q.pop();
			inQue[u] = 0;
			for(int e = head[u];~e;e = nxt[e]){
				int v = to[e];
				if(dist[v] > dist[u] + cost[e]){
					if(!cnt)
						return 0;			
					dist[v] = dist[u] + cost[e];
					if(inQue[v] != vid){
						inQue[v] = vid;
						q.push(v);
					}
						
				}
			}
		}
		
	}
	return 1;
}



int main(void){	

	fast;
	#ifdef Khaled
		freopen("in.txt","r",stdin);
		//freopen("out.txt","w",stdout);
	#endif

	cin >> n >> m;
	init();
	while(m--){
		int u,v,c;
		cin >> u >> v >> c;
		addEdge(--u,--v,c);
	}
	bellman(0);
	for(int u = 0;u<n;u++){
		cout << (dist[u] == 0x3f3f3f3f ? 30000 : dist[u]) << " \n"[u + 1 == n];
	}
}	