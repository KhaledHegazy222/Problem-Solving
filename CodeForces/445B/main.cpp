/*
	Created By : Khaled Hegazy
*/


#include <bits/stdc++.h>
#define all(x) x.begin(),x.end()
#define fast cin.tie(0),ios::sync_with_stdio(0),cout.tie(0)

using namespace std;

typedef unsigned long long ull;
typedef long long ll;

const int N = 50;
int par[N],sz[N];
void init(){
	iota(par,par+N,0);
	fill(sz,sz+N,1);
}

int find(int x){
	if(par[x] == x) return x;
	return par[x] = find(par[x]);
}

void merge(int a,int b){
	int u = find(a);
	int v = find(b);
	if(u == v) return;
	if(rand()%2) swap(u,v);
	par[v] = u;
	sz[u] += sz[v];
}


int main(void){
	fast;
	#ifdef Khaled
		freopen("out.txt","w",stdout);
		freopen("in.txt","r",stdin);
	#endif
	#ifndef Khaled
		//freopen(".in","r",stdin);
	#endif
	init();

	int n,m;
	cin >> n >> m;
	while(m--){
		int a,b;
		cin >> a >> b;
		a--,b--;
		merge(a,b);
	}
	ll ret = 1;
	for(int i = 0;i<n;i++){
		if(par[i] == i){
			ret *= 1ll << sz[i]-1;
		}
	}
	cout << ret << endl;

}
