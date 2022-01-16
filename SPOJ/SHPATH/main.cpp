
#include <bits/stdc++.h>

#define all(a) a.begin(),a.end()
#define fast cin.tie(0),ios::sync_with_stdio(0),cout.tie(0)
#define ll long long 
#define ull unsigned long long 

using namespace std;

const int N = 200000,M = 2 * N;



int head[N],nxt[M],to[M],n,m,ne;

int dist[N],cost[M];


void init(){
	memset(head,-1,n * sizeof(head[0]));
	ne =  0;
}


void addEdge(int u,int v,int cst){
	nxt[ne] = head[u];
	to[ne] = v;
	cost[ne] = cst;
	head[u] = ne++;
}



void dijistra(int src){
	
	memset(dist,0x3f,n * sizeof(dist[0]) );
	priority_queue<pair<int,int>>pq;
	dist[src] = 0;

	pq.push({0,src});
	while(pq.size()){
		int d = -pq.top().first;
		int u = pq.top().second;
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



int main(void){	
	fast;
	#ifdef Khaled
		freopen("in.txt","r",stdin);
		//freopen("out.txt","w",stdout);
	#endif



	int t;
	cin >> t;
	while(t--){
		map<string,int>names;
		cin >> n; 
		init();
		for(int i = 0;i<n;i++){
			string name;
			cin >> name;
			names[name] = i;
			int x;
			cin >> x;
			for(int j = 0;j<x;j++){
				int u,v,cst;
				u = i;
				cin >> v >> cst;
				v--;
				addEdge(u,v,cst);
			}
		}
		int q;
		cin >> q;
		while(q--){
			int st,en;
			string from,to;
			cin >> from >> to;
			st = names[from];
			en = names[to];
			dijistra(st);
			if(dist[en] == 0x3f3f3f3f )
				cout << "NO\n";
			else
				cout << dist[en] << endl;

		}
	}

}	