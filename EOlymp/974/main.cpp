
#include <bits/stdc++.h>

#define all(a) a.begin(),a.end()
#define fast cin.tie(0),ios::sync_with_stdio(0),cout.tie(0)
#define ll long long 

using namespace std;

const int N = 1e2 + 5,M = 1e4 + 5;

int head[N],nxt[M],to[M],n,m,ne;
int vis[N],vid;
int inQue[N];

int cost[M],dist[N];
int Mat[N][N];


void init(){
	ne = 0;
	memset(head,-1,(n + 1) * sizeof head[0]);
}

void addEdge(int u,int v,int c){
	nxt[ne] = head[u];
	cost[ne] = c;
	to[ne] = v;
	head[u] = ne++; 
}

void addBiEdge(int u,int v,int c){
	addEdge(u,v,c);
	addEdge(v,u,c);
}


void dijkstra(int src){
	priority_queue<pair<int,int>>pq;
	memset(dist,0x3f,(n + 1) * sizeof dist[0]);
	dist[src] = 0;
	inQue[src] = 1;
	pq.push({0,src});
	while(pq.size()){
		int u = pq.top().second;
		int d = -pq.top().first;
		pq.pop();
		inQue[u] = 0;
		for(int e = head[u];~e;e = nxt[e]){
			int v = to[e];
			if(d + cost[e] < dist[v]){
				dist[v] = d + cost[e];
				if(!inQue[v])
					pq.push({-dist[v],v}),inQue[v] = 1;
			}
		}
	}
	
}

int bellmanFord(int src){
	queue<int>q;
	memset(dist,0x3f,(n + 1) * sizeof dist[0]);
	dist[src] = 0;
	q.push(src);
	int cnt = n;
	while(cnt-- && q.size()){
		int x = q.size();
		while(x--){
			int u = q.front();
			q.pop();
			for(int e = head[u];~e;e = nxt[e]){
				int v = to[e];
				if(dist[v] > dist[u] + cost[e]){
					if(!cnt) return 0;
					q.push(v);
					dist[v] = dist[u] + cost[e];
				}
			}

		}
	}
	return 1;
}

void floyd(){
	
	for(int k = 0;k<n;k++){
		for(int i = 0;i<n;i++){
			for(int j = 0;j<n;j++){
				Mat[i][j] = min({Mat[i][j],Mat[i][k] + Mat[k][j]});
			}
		}
	}
}





int main(void){
    
	#ifdef Khaled
		freopen("in.txt","r",stdin);
		//freopen("out.txt","w",stdout);
	
    #endif


	cin >> n;
	for(int i = 0;i<n;i++){
		for(int j = 0;j<n;j++){
			cin >> Mat[i][j];
		}
	}
	floyd();
	for(int i = 0;i<n;i++){
		for(int j = 0;j<n;j++){
			cout << Mat[i][j] << " \n"[j + 1 == n];
		}
	}
}
