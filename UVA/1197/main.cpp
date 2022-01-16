
#include <bits/stdc++.h>

#define all(a) a.begin(),a.end()
#define fast cin.tie(0),ios::sync_with_stdio(0),cout.tie(0)
#define ll long long 

using namespace std;
const int N = 3e4 + 5,M = 5e2 + 5;
int par[N],sz[N],head[N],headSz;
int n,m;

int find(int x){
	if(par[x] == x)
		return x;
	return par[x] = find(par[x]);
}

void init(){
	iota(par,par + n,0);
	iota(head,head + n,0);
	fill(sz,sz + n,1);
	headSz = n;
}

int join(int a,int b){
	int u = find(a);
	int v = find(b);
	if(u == v) return 0;
	if(rand() % 2) swap(u,v);
	par[v] = u;
	sz[u] += sz[v];
	head[v] = head[--headSz];
	return 1;
}






int main(void){
    fast;
	#ifdef Khaled
		freopen("in.txt","r",stdin);
		//freopen("out.txt","w",stdout);
    #endif
	while(cin >> n >> m){
		if(!n && !m) return 0;
		init();
		while(m--){
			int k;
			cin >> k;
			int arr[k];
			for(int i = 0;i<k;i++){
				cin >> arr[i];
			}
			for(int i = 1;i<k;i++){
				join(arr[i-1],arr[i]);
			}
		}
		cout << sz[find(0)] << endl;
	}


}