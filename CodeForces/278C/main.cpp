
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
	st.clear();
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
	int x;
	cin >> x >> n;
	init();
	int frq[n] = {0};
	int res = 0;
	for(int i = 0;i<x;i++){
		int k;
		cin >> k;
		res += !k;
		vector<int>v(k);
		for(int i = 0;i<k;i++){
			cin >> v[i];
			v[i]--;
			frq[v[i]]++;
			if(i)
				join(v[i],v[i-1]);
		}
	}
	int cnt = 0;
	for(auto it : st){
		if(frq[it])
			cnt++;
	}
	cout << res + max(cnt - 1,0) << '\n';

	

}