
#include <bits/stdc++.h>

#define all(a) a.begin(),a.end()
#define fast cin.tie(0),ios::sync_with_stdio(0),cout.tie(0)
#define ll long long 
#define ull unsigned long long 

using namespace std;



const int N = 1e5 + 5,M = 1e5;
int found = 0;
int isGray[N];
int vis[N],vid;
stack<int>stk;
vector<int>vec;



int head[N],nxt[M],to[M],n,m,ne;	
	
void init(){
	ne = 0;
	memset(head,-1,N * sizeof(head[0]));
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



void dfs(int u){
	isGray[u] = 1;
	vis[u] = 1;
	stk.push(u);
	for(int e = head[u];~e;e = nxt[e]){
		int v = to[e];
		if(found)
			return;
		if(isGray[v]){
			cout << "YES\n";
			found = 1;
			while(stk.size() && stk.top() != v){
				vec.push_back(stk.top() + 1);
				stk.pop();
			}
			vec.push_back(v + 1);
			return;
		}
		dfs(v);
	}
	isGray[u] = 0;
	if(found)
		return;
	stk.pop();
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
		int u,v;
		cin >> u >> v;
		u--,v--;
		addEdge(u,v);
	}

	for(int u = 0;u<n && !found;u++){
		if(!vis[u])
			dfs(u);		
	}

	
	if(found){
		for(int i = vec.size() - 1;i>=0;i--){
			cout << vec[i] << " ";
		}
		cout << endl;
	}
	else{
		cout << "NO\n";
	}



}	
