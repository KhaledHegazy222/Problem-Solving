/*
	Created By : Khaled Hegazy
*/


#include <bits/stdc++.h>


#define fast cin.tie(0),ios::sync_with_stdio(0),cout.tie(0)
#define ll long long 

using namespace std;
const int N = 1 << 15;


bool isPrime(int n){
	if(n == 2) return 1;
	if(n % 2 == 0) return 0;
	for(ll i = 3;i*i <= n; i+= 2){
		if(n % i == 0){
			return 0;
		}
	}


	return 1;

}

struct node{ 
	bool allprime;
	int cnt,lazy;

	void modify(int val,int ni,int ns,int ne){
		cnt = (allprime = isPrime(val)) * (ne - ns + 1);
		lazy = val;
	}
}tree[ N << 1];

int arr [N];
int n,q;



node merge(node &a,node &b){
	node ret;
	ret.allprime = a.allprime & b.allprime;
	ret.cnt = a.cnt + b.cnt;
	ret.lazy = 0;
	return ret;
}

void push_down(int ni,int ns,int ne){
	if(!tree[ni].lazy || ns == ne) return;
	
	int l = ni * 2 + 1,r = l + 1,mid = ns + (ne - ns) / 2;
	tree[l].modify(tree[ni].lazy,l,ns,mid);
	tree[r].modify(tree[ni].lazy,r,mid+1,ne);
	tree[ni] = merge(tree[l],tree[r]);
}


void build(int ni = 0,int ns = 0,int ne = n-1){

	if(ne == ns){
		int tmp = isPrime(arr[ns]);
		tree[ni] = {(bool)tmp,tmp,0};
		return;
	}


	int l = ni * 2 + 1,r = l + 1,mid = ns + (ne - ns) / 2;

	build(l,ns,mid);
	build(r,mid+1,ne);

	tree[ni] = merge(tree[l],tree[r]);

}


int query(int qs,int qe,int ni = 0,int ns = 0,int ne = n - 1){
	if(qs > ne || ns > qe) return 0;
	if(ns >= qs && ne <= qe) return tree[ni].cnt;

	push_down(ni,ns,ne);

	int l = ni * 2 + 1,r = l + 1,mid = ns + (ne - ns) / 2;
	return query(qs,qe,l,ns,mid) + query(qs,qe,r,mid+1,ne);
}

void update(int qs,int qe,int val,int ni = 0,int ns = 0,int ne = n - 1){
	if(qs > ne || ns > qe) return;
	if(ns >= qs && ne <= qe){
		tree[ni].modify(val,ni,ns,ne);
		return;
	}
	push_down(ni,ns,ne);
	int l = ni * 2 + 1,r = l + 1,mid = ns + (ne - ns) / 2;
	update(qs,qe,val,l,ns,mid);
	update(qs,qe,val,r,mid+1,ne);
	tree[ni] = merge(tree[l],tree[r]);
}



int main(void){

	fast;

	#ifdef Khaled
		freopen("in.txt","r",stdin);
		freopen("out.txt","w",stdout);
	#endif

	int t;
	cin >> t;
	int cs = 1;
	while(t--){
		cout << "Case " << cs++ << ":\n";
		cin >> n >> q;
		for(int i = 0 ; i <n;i++){
			cin >> arr[i];
		}
		build();
		while(q--){
			int typ,st,en;
			cin >> typ >> st >> en;
			st--,en--;
			if(typ){
				cout << query(st,en) << endl;
			}
			else{
				int val;
				cin >> val;
				update(st,en,val);
			}

		}
	}



}