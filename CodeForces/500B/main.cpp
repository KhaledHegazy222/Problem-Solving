/*
	Created By : Khaled Hegazy
*/


#include <bits/stdc++.h>


#define fast cin.tie(0),ios::sync_with_stdio(0),cout.tie(0)
#define ll long long 
using namespace std;


const int N = 300 + 2;
int n;


int par[N],arr[N];
vector<vector<int>>ls;
void init(){
	ls.resize(n);
	iota(par,par+n,0);
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

	par[v] = u;
}






int main(void){

	#ifdef Khaled
		freopen("in.txt","r",stdin);
		freopen("out.txt","w",stdout);


	#endif


	cin >> n;

	init();

	for(int i = 0;i<n;i++){
		cin >> arr[i];
	}

	for(int i = 0;i<n;i++){
		for(int j = 0;j<n;j++){
			char x;
			cin >> x;
			if(x == '1')
				join(i,j);
		}
	}

	for(int i = 0;i<n;i++){
		ls[find(i)].push_back(i);
	}

	for(int i = 0;i<n;i++){
		sort(ls[i].begin(),ls[i].end());
		vector<int>tmp;
		for(int j = 0;j<ls[i].size();j++){
			tmp.push_back(arr[ls[i][j]]);
		}
		sort(tmp.begin(),tmp.end());
		for(int j = 0;j<ls[i].size();j++){
			arr[ls[i][j]] = tmp[j];
		}
	}



	for(int i = 0;i<n;i++){
		cout << arr[i] << " ";
	}
	cout << endl;



}