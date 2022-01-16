
#include <bits/stdc++.h>

#define all(a) a.begin(),a.end()
#define fast cin.tie(0),ios::sync_with_stdio(0),cout.tie(0)
#define ll long long 
#define ull unsigned long long 

using namespace std;
const int N = 1e5 + 5,M = 1e6 + 5;
int head[N],to[M],nxt[M],n,q,ne;

void init(){
	memset(head,-1,n * sizeof(head[0]));
	ne = 0;
}


void addEdge(int u,int v){
	nxt[ne] = head[u];
	to[ne] = v;
	head[u] = ne++;
}

void addBiEdge(int u,int v){
	addEdge(u,v);
	addEdge(v,u);
}


int main(void){	
	//fast;
	#ifdef Khaled
		freopen("in.txt","r",stdin);
		//freopen("out.txt","w",stdout);
	#endif
	cin >> n >> q;
	init();
	while(q--){
		int t;
		cin >> t;
		if(t - 1){
			int u;
			cin >> u;
			u--;
			for(int e = head[u];~e;e = nxt[e]){
				int v = to[e];
				cout << v + 1 << " ";
			}
			cout << endl;
		}
		else{
			int u,v;
			cin >> u >> v;
			u--,v--;
			addBiEdge(u,v);	
		}
	}

}	