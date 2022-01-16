
#include <bits/stdc++.h>

#define all(a) a.begin(),a.end()
#define fast cin.tie(0),ios::sync_with_stdio(0),cout.tie(0)
#define ll long long 

using namespace std;
const int N = 3e4 + 5,M = 5e2 + 5;
int par[N],sz[N];
int n,m;
set<int>st;
int find(int x){
	if(par[x] == x)
		return x;
	return par[x] = find(par[x]);
}

void init(){
	iota(par,par + n,0);
	fill(sz,sz + n,1);
	for(int i = 0;i<n;i++){
		st.insert({i});
	}
}

int join(int a,int b){
	int u = find(a);
	int v = find(b);
	if(u == v) return 0;
	if(rand() % 2) swap(u,v);
	par[v] = u;
	sz[u] += sz[v];
	st.erase(v);
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
	for(int i = 0;i<m;i++){
		int a,b;
		cin >> a >> b;
		join(--a,--b);
	}
	ll res = 1;
	for(auto it : st){
		int x = sz[find(it)];
		res *= 1ll << (x - 1);
	}
	cout << res << '\n';
	

}