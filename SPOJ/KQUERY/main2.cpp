/*
	Created By : Khaled Hegazy
*/


#include <bits/stdc++.h>


#define fast cin.tie(0),ios::sync_with_stdio(0),cout.tie(0)

using namespace std;

const int N = 1 << 15;
int n;

vector<int>tree[N << 1];
int arr[N];

void build(int ni = 0,int ns = 0,int ne = n - 1){
	if(ns == ne){
		tree[ni].push_back(arr[ns]);
		return;
	}
	int l = ni * 2 + 1;
	int r = l + 1;
	int mid = ns + (ne - ns) / 2;
	build(l,ns,mid);
	build(r,mid+1,ne);
	for(auto it : tree[l]){
		tree[ni].push_back(it);
	}
	for(auto it : tree[r]){
		tree[ni].push_back(it);
	}
	sort(tree[ni].begin(),tree[ni].end());
}

int query(int qs,int qe,int val,int ni = 0,int ns = 0,int ne = n - 1){
	if(qs > ne  || qe < ns) return 0;
	if(ns >= qs && ne <= qe) return (tree[ni].end() - upper_bound(tree[ni].begin(),tree[ni].end(),val));

	int l = ni * 2 + 1;
	int r = l + 1;
	int mid = ns + (ne - ns) / 2; 
	return query(qs,qe,val,l,ns,mid) + query(qs,qe,val,r,mid+1,ne);
}







int main(void){
	fast;


	#ifdef Khaled 
		freopen("in.txt","r",stdin);
		freopen("out.txt","w",stdout);
	#endif

	cin >> n;
	for(int i = 0;i<n;i++){
		cin >> arr[i];
	}
	build();
	int q;
	cin >> q;
	while(q--){
		int i,j,k;
		cin >> i >> j >> k;
		cout << query(--i,--j,k) << endl;
	}




}