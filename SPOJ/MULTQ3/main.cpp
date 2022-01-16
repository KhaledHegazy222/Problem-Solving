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
	int one,two,three;
	int lazy;
	void add(int val,int ni,int ns,int ne){
		val %= 3;
		lazy += val;
		lazy %= 3;

		for(int i = 0;i < val;i++){
			int x = three;
			three = two;
			two = one;
			one = x;
		}

	}


}tree[N << 1];




node merge(node &l,node &r){
	node ret;
	ret.three = l.three + r.three;
	ret.two = l.two + r.two;
	ret.one = l.one + r.one;
	ret.lazy = 0;
	return ret;
}


void push_down(int ni,int ns,int ne){
	if(!tree[ni].lazy || ns == ne) return;
	int l = ni * 2 + 1;
	int r = l + 1;
	int mid = ns + (ne - ns) / 2;

	tree[l].add(tree[ni].lazy,l,ns,mid);
	tree[r].add(tree[ni].lazy,r,mid+1,ne);
	tree[ni].lazy = 0;
}

void build(int ni = 0,int ns = 0,int ne = n - 1){
	if(ns == ne){
		tree[ni].one = tree[ni].two = tree[ni].lazy = 0;
		tree[ni].three = 1; 
		return;
	}


	int l = ni * 2 + 1;
	int r = l + 1;
	int mid = ns + (ne - ns) / 2;

	build(l,ns,mid);
	build(r,mid+1,ne);
	tree[ni] = merge(tree[l],tree[r]);
	
	tree[ni].lazy = 0;

}





void update(int qs,int qe,int ni = 0,int ns = 0,int ne = n - 1){
	if(qs > ne || qe < ns) return;
	if(ns >= qs && ne <= qe) return tree[ni].add(1,ni,ns,ne);
	push_down(ni,ns,ne);
	

	int l = ni * 2 + 1;
	int r = l + 1;
	int mid = ns + (ne - ns) / 2;

	update(qs,qe,l,ns,mid);
	update(qs,qe,r,mid+1,ne);
	tree[ni] = merge(tree[l],tree[r]);



}


int query(int qs,int qe,int ni = 0,int ns = 0,int ne = n - 1){
	if(qs > ne || qe < ns) return 0;
	if(ns >= qs && ne <= qe) return tree[ni].three;
	push_down(ni,ns,ne);
	int l = ni * 2 + 1;
	int r = l + 1;
	int mid = ns + (ne - ns) / 2;


	return query(qs,qe,l,ns,mid) + query (qs,qe,r,mid+1,ne);
}







int main(void){
	

	#ifdef Khaled 
		freopen("in.txt","r",stdin);
		freopen("out.txt","w",stdout);
	#endif


	int q;
	cin >> n >> q;
	build();



	while(q--){
		int t,st,en;
		cin >> t >> st >> en;

			
		if(t){
			cout << query(st,en) << endl;
		}
		else{	
			update(st,en);

		}
		
	}


}