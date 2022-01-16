/*
	Created By : Khaled Hegazy
*/


#include <bits/stdc++.h>


#define fast cin.tie(0),ios::sync_with_stdio(0),cout.tie(0)
#define ll long long 
using namespace std;

const int N = 1 << 17;
int n;

struct node{
	int max;
	ll sum;
}tree[N << 1];

int arr[N];

node merge(node &l,node &r){
	node ret;
	ret.sum = l.sum + r.sum;
	ret.max = max(l.max,r.max);
	return ret;
}


void build(int ni = 0,int ns = 0,int ne = n - 1){
	if(ns == ne){
		tree[ni].max = tree[ni].sum = arr[ns];
		return;
	}

	int l = ni * 2 + 1;
	int r = l + 1;
	int mid = ns + (ne - ns) / 2;

	build(l,ns,mid);
	build(r,mid+1,ne);

	tree[ni] = merge(tree[l],tree[r]);
}


void update(int qs,int qe,int mod,int ni = 0,int ns = 0,int ne = n - 1){
	if(qs > ne || qe < ns) return;
	if(ns >= qs && ne <= qe && tree[ni].max < mod) return;
	if(ns == ne){
		tree[ni].max = (tree[ni].sum %= mod);
		return; 
	}
	
	int l = ni * 2 + 1;
	int r = l + 1;
	int mid = ns + (ne - ns) / 2;
	update(qs,qe,mod,l,ns,mid);
	update(qs,qe,mod,r,mid+1,ne);
	tree[ni] = merge(tree[l],tree[r]);

}

ll query(int qs,int qe,int ni = 0,int ns = 0,int ne = n - 1){
	if(qs > ne || qe < ns) return 0;
	if(ns >= qs && ne <= qe) return tree[ni].sum;
	int l = ni * 2 + 1;
	int r = l + 1;
	int mid = ns + (ne - ns) / 2;
	
	return query(qs,qe,l,ns,mid) + query(qs,qe,r,mid+1,ne);

}


void setx(int pos,int val,int ni = 0,int ns = 0,int ne = n - 1){
	if(pos < ns || pos > ne) return;
	if(ns == ne){
		tree[ni].sum = tree[ni].max = val;
		return;
	}
	int l = ni * 2 + 1;
	int r = l + 1;
	int mid = ns + (ne - ns) / 2;
	setx(pos,val,l,ns,mid);
	setx(pos,val,r,mid + 1,ne);
	tree[ni] = merge(tree[l],tree[r]);

}










int main(void){

	#ifdef Khaled
		freopen("in.txt","r",stdin);
		freopen("out.txt","w",stdout);
	#endif
	int q;
	cin >> n >> q;
	for(int i = 0;i<n;i++){
		cin >> arr[i];
	}
	build();

	while(q--){
		int t;
		cin >> t;
		if(t == 1){
			int l,r;
			cin >> l >> r;
			--l,--r;
			cout << query(l,r) << endl;
		}
		else if(t == 2){
			int l,r,x;
			cin >> l >> r >> x;
			--l,--r;
			update(l,r,x);
		}
		else{
			int pos,x;
			cin >> pos >> x;
			--pos;
			setx(pos,x);
		}
	}



}