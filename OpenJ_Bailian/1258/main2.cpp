
#include <bits/stdc++.h>

#define all(a) a.begin(),a.end()
#define fast cin.tie(0),ios::sync_with_stdio(0),cout.tie(0)
#define ll long long 
#define ull unsigned long long 

using namespace std;
const int N = 100 + 5;
int n;

int par[N],sz[N];
priority_queue<pair<int,pair<int,int> >>pq;

void init(){
	iota(par,par + n,0);
	fill(sz,sz + n,1);
}


int find(int x){
	if(par[x] == x) return x;
	return par[x] = find(par[x]);
}

void join(int a,int b){
	int u = find(a);
	int v = find(b);
	if(u == v) return;
	if(rand() % 2) swap(u,v);
	par[u] = v;
}


int main(void){	
	fast;
	#ifdef Khaled
		freopen("in.txt","r",stdin);
		//freopen("out.txt","w",stdout);
	#endif
	
	while(cin >> n){
		init();
		for(int i = 0;i<n;i++){
			for(int j = 0;j<n;j++){
				int cost;
				cin >> cost;
				pq.push({-cost,{i,j}});
			}
		}
		int res = 0;

		
		while(pq.size()){
			auto e = pq.top();
			int u = e.second.first;
			int v = e.second.second;
			int c = -e.first;
			pq.pop();
			if(find(u) != find(v))
				res += c;
			join(u,v);
		}
		cout << res << endl;

			
		
		

	}

}	