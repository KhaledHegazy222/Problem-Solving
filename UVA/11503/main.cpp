#include <bits/stdc++.h>
#define fast cin.tie(0),ios::sync_with_stdio(0),cout.tie();
#define all(a) a.begin(),a.end()

typedef long long ll;
typedef unsigned long long ull;

using namespace std;

const int N = 4e5 + 5;


struct DSU{
	int par[N];
	int sz[N];
	void init(int n){
		iota(par,par + n,0);
		fill(sz,sz + n,1);
	}

	int find(int x){
		if(par[x] == x)
			return x;
		return par[x] = find(par[x]);
	}

	int join(int a,int b){
		a = find(a);
		b = find(b);
		if(a == b)
			return 0;
		if(rand() % 2)
			swap(a,b);
		par[b] = a; 
		sz[a] += sz[b];
		return 1;
	}

}dsu;



signed main(void){

	#ifdef Khaled
		freopen("in.txt","r",stdin);
		//freopen("out.txt","w",stdout);
	#endif
	#ifndef Khaled
		#define endl '\n'
		fast;
	#endif
	int t;
	cin >> t;
	while(t--){
		int n;
		cin >> n;
		dsu.init(n * 4);
		map<string,int>mp;
		for(int i = 0;i < n;i++){
			string a,b;
			cin >> a >> b;
			int u,v;
			if(mp.find(a) != mp.end())
				u = mp[a];
			else
				u = mp[a] = mp.size();
				
			if(mp.find(b) != mp.end())
				v = mp[b];
			else
				v = mp[b] = mp.size();
				
			dsu.join(u,v); 
			cout << dsu.sz[dsu.find(u)] << endl;
		}
	}	

}


