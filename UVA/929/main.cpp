
#include <bits/stdc++.h>

#define all(a) a.begin(),a.end()
#define fast cin.tie(0),ios::sync_with_stdio(0),cout.tie(0)
#define ll long long 

using namespace std;

const int N = 1e6 + 5,M = 4*N + 5;

int head[N],nxt[M],to[M],n,m,ne;
int vis[N],vid;

int cost[M],dist[N];

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
	pq.push({0,src});
	while(pq.size()){
		int u = pq.top().second;
		int d = -pq.top().first;
		pq.pop();
		for(int e = head[u];~e;e = nxt[e]){
			int v = to[e];
			if(d + cost[e] < dist[v]){
				dist[v] = d + cost[e];
				pq.push({-dist[v],v});
			}
		}
	}
	
}

int w,h;

int dx[4] = {1,0,-1,0};
int dy[4] = {0,1,0,-1};

int valid(int i,int j){
	return i >= 0 && j >= 0 && i < h && j < w;
}




int main(void){
    
	#ifdef Khaled
		freopen("in.txt","r",stdin);
		//freopen("out.txt","w",stdout);
	
    #endif
	int t;
	cin >> t;
	while(t--){
		cin >> h >> w;
		n = w * h;
		init();
		int grid[h][w];
		for(int i = 0;i<h;i++){
			for(int j = 0;j<w;j++){
				cin >> grid[i][j];
			}
		}
		for(int i = 0;i<h;i++){
			for(int j = 0;j<w;j++){
				for(int k = 0;k<4;k++){
					int ii = i + dx[k];
					int jj = j + dy[k];
					if(valid(ii,jj))
						addEdge(i*w+j,ii*w+jj,grid[ii][jj]);
				}
			}
		}
		dijkstra(0);
		cout << dist[n - 1] + grid[0][0] << endl;
	}
	
}