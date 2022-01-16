
//#include <bits/stdc++.h>
#include <iostream>
#include <cstring>

#define fast cin.tie(0),ios::sync_with_stdio(0),cout.tie(0)
#define all(a) a.begin(),a.end()
#define ll long long 
#define ull unsigned long long 

using namespace std;

const int N = 1e3 + 5;
int adjMat[N][N],dist[N],notVis[N],notVisSz,n;






int prim(int src){
	memset(dist,0x3f,n * sizeof dist[0]);
	notVisSz = n;
	for(int i = 0;i<n;i++){
		notVis[i] = i;
	}
	dist[src] = 0;
	int nxt = src,best = 0;

	int res = 0;
	while(nxt != -1){
		res += best;
		int u = notVis[nxt];
		notVis[nxt] = notVis[--notVisSz];
		nxt = -1;
		best = 0x3f3f3f3f;
		for(int i = 0;i<notVisSz;i++){
			int v = notVis[i];
			if(dist[v] > adjMat[u][v])
				dist[v] = adjMat[u][v];
			if(dist[v] < best)
				best = dist[v],nxt = i;
		}
	}
	return res;
}





int main(void){	

	fast;
	#ifdef Khaled
		freopen("in.txt","r",stdin);
		//freopen("out.txt","w",stdout);
	#endif

	while(cin >> n){

		memset(adjMat,0x3f,sizeof adjMat);
		for(int i = 0;i<n;i++){
			for(int j = 0;j<n;j++){
				cin >> adjMat[i][j];
			}
		}
		cout << prim(0) << endl;
	}

}	