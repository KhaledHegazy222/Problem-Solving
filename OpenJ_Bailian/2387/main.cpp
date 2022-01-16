
#include <bits/stdc++.h>

#define fast cin.tie(0),ios::sync_with_stdio(0),cout.tie(0)
#define all(a) a.begin(),a.end()
#define ll long long 
#define ull unsigned long long 

using namespace std;

const int N = 1e3 + 5;
int adjMat[N][N],dist[N],notVis[N],notVisSz,n;






void dijsktra(int src){

	memset(dist,0x3f,n * sizeof dist[0]);
	notVisSz = n;
	iota(notVis,notVis + n,0);
	dist[src] = 0;
	int nxt = src,best;

	while(nxt != -1){
		int u = notVis[nxt];
		notVis[nxt] = notVis[--notVisSz];
		nxt = -1;
		best = 0x3f3f3f3f;
		for(int i = 0;i<notVisSz;i++){
			int v = notVis[i];
			if(dist[v] > dist[u] + adjMat[u][v])
				dist[v] = dist[u] + adjMat[u][v];
			if(dist[v] < best)
				best = dist[v],nxt = i;
		}
	}

}





int main(void){	

	fast;
	#ifdef Khaled
		freopen("in.txt","r",stdin);
		//freopen("out.txt","w",stdout);
	#endif

	int m;
	cin >> m >> n;
	memset(adjMat,0x3f,sizeof adjMat);
	while(m--){
		int u,v,d;
		cin >> u >> v >> d;
		u--,v--;
		adjMat[u][v] = adjMat[v][u] = min(adjMat[v][u],d);
	}
	dijsktra(0);
	cout << dist[n-1] << endl;

}	