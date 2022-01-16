
#include <bits/stdc++.h>

#define all(a) a.begin(),a.end()
#define fast cin.tie(0),ios::sync_with_stdio(0),cout.tie(0)
#define ll long long 

using namespace std;
const int N = 5e4 + 5,M = N * (N - 1) / 2;
int par[N];
int n,m;

int find(int x){
	if(par[x] == x)
		return x;
	return par[x] = find(par[x]);
}

void init(){
	iota(par,par + n,0);;
}

int join(int a,int b){
	int u = find(a);
	int v = find(b);
	if(u == v) return 0;
	if(rand() % 2) swap(u,v);
	par[v] = u;
	return 1;
}





int main(void){
    
	#ifdef Khaled
		freopen("in.txt","r",stdin);
		//freopen("out.txt","w",stdout);
	
    #endif
	int cs = 1;
	while(cin >> n >> m){
		if(!n && !m) return 0;
		init();
		int res = n;
		for(int i = 0;i<m;i++){
			int u,v;
			cin >> u >> v;
			if(join(--u,--v))
				res--;
		}
		cout << "Case " << cs++ << ": " << res << '\n'; 

	}
}