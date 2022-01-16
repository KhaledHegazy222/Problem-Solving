
#include <bits/stdc++.h>

#define all(a) a.begin(),a.end()
#define fast cin.tie(0),ios::sync_with_stdio(0),cout.tie(0)
#define ll long long 
#define ull unsigned long long 

using namespace std;

const int N = 1e5 + 5,M = 3e5 + 5,MOD = 1e9 + 7;


int head[N],nxt[M],to[M],inDeg[N],res[N],resSz,ne,n,m;


void init(){
	memset(head,-1,n * sizeof(head[0]));
	ne =  0;
}


void addEdge(int u,int v){
	nxt[ne] = head[u];
	to[ne] = v;
	inDeg[v]++;
	head[u] = ne++;

}


void topo(){
	queue<int>q;
	for(int i = 0;i<n;i++){
		if(!inDeg[i])
			q.push(i);
	}

	while(q.size()){
		int u = q.front();
		res[resSz++] = u;
		q.pop();
		for(int e = head[u];~e;e = nxt[e]){
			int v = to[e];
			if(!--inDeg[v])
				q.push(v);
		}
	}
}



int main(void){	
	//fast;
	#ifdef Khaled
		freopen("in.txt","r",stdin);
		//freopen("out.txt","w",stdout);
	#endif


	n = 26;
	init();

	int x;
	cin >> x;
	vector<string>v(x);
	for(int i = 0;i<x;i++){
		cin >> v[i];
	}
	for(int i = 1;i<x;i++){
		int idx = 0;
		while(idx < min(v[i].size(),v[i-1].size()) && v[i][idx] == v[i - 1][idx]){
			idx++;
		}
		if(idx >= min(v[i].size(),v[i-1].size())){
			if(v[i].size() < v[i-1].size()){	
				cout << "Impossible\n";
				return 0;
			}
		}
		else{
			addEdge( v[i-1][idx] - 'a', v[i][idx] - 'a');
		}
	} 

	topo();
	if(resSz != n){
		cout << "Impossible\n";
	}
	else{
		for(int i = 0;i<n;i++){
			char c = res[i] + 'a';
			cout << c;
		}
		cout << endl;
	}

}	