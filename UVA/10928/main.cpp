#include <bits/stdc++.h>
#define fast cin.tie(0),ios::sync_with_stdio(0),cout.tie();
#define all(a) a.begin(),a.end()

typedef long long ll;
typedef unsigned long long ull;

using namespace std;

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
		vector<vector<int>>adj(n);
		cin.ignore();
		for(int i = 0;i < n;i++){
			string line;
			getline(cin,line);
			stringstream ss(line);
			int v;
			while(ss >> v){
				adj[i].push_back(--v);
			}
		}
		int mn = n;
		for(int i = 0;i < n;i++)
			mn = min(mn,(int)adj[i].size());
		vector<int>res;
		for(int i = 0;i < n;i++)
			if(adj[i].size() == mn)
				res.push_back(i + 1);

		for(int i = 0;i < res.size();i++)
			cout << res[i] << " \n"[i + 1 == res.size()];	

	}

}


