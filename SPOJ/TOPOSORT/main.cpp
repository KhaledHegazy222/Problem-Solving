
#include <bits/stdc++.h>

#define all(a) a.begin(),a.end()
#define fast cin.tie(0),ios::sync_with_stdio(0),cout.tie(0)
#define ll long long 

using namespace std;

const int N = 1e4 + 5,M = 1e6 + 5;

int head[N],nxt[M],to[M],n,m,ne;
int res[N],resSz;
int inDeg[N];

void init(){
	ne = 0;
	memset(head,-1,(n + 1) * sizeof head[0]);
}

void addEdge(int u,int v){
	inDeg[v]++;
	nxt[ne] = head[u];
	to[ne] = v;
	head[u] = ne++; 
}

void addBiEdge(int u,int v){
	addEdge(u,v);
	addEdge(v,u);
}

void topo(){
	priority_queue<int>pq;
	for(int i = 0;i<n;i++){
		if(!inDeg[i])
			pq.push(-i);
	}
	while(pq.size()){
		int u = -pq.top();
		pq.pop();
		res[resSz++] = u;
		for(int e = head[u];~e;e = nxt[e]){
			int v = to[e];
			if(!--inDeg[v])
				pq.push(-v);
		}
	}
}




int main(void){
    
	#ifdef Khaled
		freopen("in.txt","r",stdin);
		//freopen("out.txt","w",stdout);
	
    #endif

    cin >> n >> m;
	init();
	for(int i = 0;i<m;i++){
		int u,v;
		cin >> u >> v;
		u--,v--;
		addEdge(u,v);
	}
	topo();
	if(resSz != n)
		cout << "Sandro fails.\n";
	else
		for(int i = 0;i<resSz;i++)
			cout << res[i] + 1 << " \n"[i + 1 == resSz];
		
}