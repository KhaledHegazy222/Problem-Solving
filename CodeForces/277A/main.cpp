/*
	Created By : Khaled Hegazy
*/


#include <bits/stdc++.h>
#define all(x) x.begin(),x.end()
#define fast cin.tie(0),ios::sync_with_stdio(0),cout.tie(0)

using namespace std;

typedef unsigned long long ull;
typedef long long ll;
const int N = 101;

vector<vector<int>>emp(N);
int lang[N];


int first_lang = -1;

int par[N];

int find(int x){
	if(par[x] == x) return x;
	return par[x] = find(par[x]);
}


void merge(int a,int b){
	int u = find(a);
	int v = find(b);
	if(u == v) return;
	if(rand() % 2) swap(u,v);

	par[v] = u;

}




int main(void){
	fast;
	#ifdef Khaled
		freopen("out.txt","w",stdout);
		freopen("in.txt","r",stdin);
	#endif
	#ifndef Khaled
		//freopen(".in","r",stdin);
	#endif


	iota(par,par+N,0);

	int n,m;
	cin >> n >> m;
	for(int i = 0;i<n;i++){
		int x;
		cin >> x;
		while(x--){
			int z;
			cin >> z;
			emp[i].push_back(--z);
			lang[z] = 1;
			if(!(~first_lang)) first_lang = z;
		}
	}
	int cost = 0;
	for(int i = 0;i<n;i++){
		if(!emp[i].size()){
			emp[i].push_back(first_lang);
			cost++;
		}
		else{
			for(int j = 1;j<emp[i].size();j++){
				merge(emp[i][j],emp[i][j-1]);
			}
		}
	}


	set<int>st;
	for(int i = 0;i<m;i++){
		if( lang[i]) st.insert(find(i));
	}
	
	if(!~first_lang) 
		cout << cost << endl;
	else
		cout << cost + st.size() - 1 << endl;
	



	
}
