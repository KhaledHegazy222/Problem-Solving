
#include <bits/stdc++.h>

#define all(a) a.begin(),a.end()
#define fast cin.tie(0),ios::sync_with_stdio(0),cout.tie(0)
#define ll long long 

using namespace std;
const int N = 3e4 + 5,M = 5e2 + 5;
int par[N],sz[N];
int n,m;
set<int>st;

vector<pair<int,int>>v;
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
	cin >> n;
	init();
	for(int i = 0;i<n - 1;i++){
		int a,b;
		cin >> a >> b;
		if(!join(--a,--b))
			v.push_back({a,b});
	}
	cout << v.size() << '\n';
	vector<int>res;
	for(auto it : st){
		res.push_back(it);	
	}
	for(int i = 1;i<res.size();i++){
		cout << v[i-1].first + 1<< " " << v[i-1].second + 1 << " " << res[i - 1] + 1 << " " << res[i] + 1 << '\n';
	}

	

}