
#include <bits/stdc++.h>
#define all(x) x.begin(),x.end()
#define fast cin.tie(0),ios::sync_with_stdio(0),cout.tie(0)

using namespace std;

typedef unsigned long long ull;
typedef long long ll;


int main(void){
	fast;
	#ifdef Khaled
		freopen("out.txt","w",stdout);
		freopen("in.txt","r",stdin);
	#endif
	#ifndef Khaled
		//freopen(".in","r",stdin);
	#endif
	int n;
	cin >> n;
	vector<pair<int,int>>edges(n-1);
	vector<int>colors(n);
	for(int i = 0;i<n-1;i++){	
		cin >> edges[i].first >> edges[i].second;
		edges[i].first--,edges[i].second--;
	}
	for(int i = 0;i<n;i++){
		cin >> colors[i];
	}

	map<int,int>freq;
	int x = 0;
	for(int i = 0;i<n-1;i++){
		if(colors[edges[i].first] != colors[edges[i].second]){
			x++;
			freq[edges[i].first]++;
			freq[edges[i].second]++;
		}
	}
	if(freq.empty()){
		cout << "YES\n" << 1 << endl;
	}
	else{
		for(auto it : freq){
			if(it.second == x){
				cout << "YES\n" << it.first + 1 << '\n';
				return 0;
			}
		}
		cout << "NO\n";

	}



}
