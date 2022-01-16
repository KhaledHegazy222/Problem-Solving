/*
	Created By : Khaled Hegazy
*/


#include <bits/stdc++.h>


#define fast cin.tie(0),ios::sync_with_stdio(0),cout.tie(0)
#define ll long long 
using namespace std;


const int N = 1 << 19;
int n;

int arr[N];

map<int,int>mem;



struct node{
	
	int max;
	ll sum;

}tree[N << 1];



int div_num(int n){
	int ret = mem[n];
	if(ret) return ret;

	if(n == 1) return 1;
	int cnt = 1;
	for(ll i = 2;i * i <= n;i++){
		if(n % i == 0){
			if(n / i != i) 
				cnt += 2;
			else
				cnt++;
		}
	}
	return mem[n] = cnt + 1;
}







node merge(node & l,node & r){
	node ret;
	ret.max = max(l.max,r.max);
	ret.sum = l.sum + r.sum;
	return ret;
}


void build(int ni = 0,int ns = 0,int ne = n-1){
	if(ne == ns){
		tree[ni].sum = tree[ni].max = arr[ns];
		return;
	}

	int l = ni * 2 + 1;
	int r = l + 1;
	int mid = ns + (ne - ns) / 2;
	build(l,ns,mid);
	build(r,mid+1,ne);
	tree[ni] = merge(tree[l],tree[r]);
}


void update(int qs,int qe,int ni = 0,int ns = 0,int ne = n-1){
	if(qs > ne || qe < ns) return;
	if(ns >= qs && ne <= qe && tree[ni].max <= 2) return;
	
	if(ns == ne){
		tree[ni].sum = tree[ni].max = div_num(tree[ni].max);
		return;
	}
	int l = ni * 2 + 1;
	int r = l + 1;
	int mid = ns + (ne - ns) / 2;

	update(qs,qe,l,ns,mid);
	update(qs,qe,r,mid+1,ne);
	tree[ni] = merge(tree[l],tree[r]);
}

ll query(int qs,int qe,int ni = 0,int ns = 0,int ne = n-1){
	if(qs > ne || qe < ns) return 0;
	if(ns >= qs && ne <= qe) return tree[ni].sum;
	
	int l = ni * 2 + 1;
	int r = l + 1;
	int mid = ns + (ne - ns) / 2;

	return query(qs,qe,l,ns,mid) + query(qs,qe,r,mid+1,ne);

}









int main(void){
	fast;

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
		int type,l,r;
		cin >> type >> l >> r;
		--l,--r;
		if(type == 1){
			update(l,r);
		}
		else{
			cout << query(l,r) << endl;
		}
	}


}