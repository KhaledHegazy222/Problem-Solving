/*
	Created By : Khaled Hegazy
*/


#include <bits/stdc++.h>

#define all(a) a.begin(),a.end()
#define fast cin.tie(0),ios::sync_with_stdio(0),cout.tie(0)
#define ll long long 

using namespace std;

const int N = 1 << 15;

int n,q,arr[N];

struct node{
	int rl; // <-)))))
	int rr; // 			((((->
}tree[N << 1];


// 0 => ( 
// 1 => )

node merge(node &l,node &r){
	node ret;
	ret.rl = l.rl + max(0,r.rl - l.rr);
	ret.rr = r.rr + max(0,l.rr - r.rl);
	return ret;
}




void build(int ni = 0,int ns = 0,int ne = n - 1){
	if(ns == ne){
		tree[ni] = {arr[ns] == 1,arr[ns] == 0}; 
		return;
	}

	int l = ni * 2 + 1,r = l + 1, mid = ns + (ne - ns) / 2;
	build(l,ns,mid);
	build(r,mid+1,ne);

	tree[ni] = merge(tree[l],tree[r]);

}


void update(int pos,int ni = 0,int ns = 0,int ne = n - 1){
	if(pos > ne || pos < ns) return;
	if(ns == ne){
		arr[ns] = !arr[ns];
		tree[ni] = {arr[ns] == 1,arr[ns] == 0}; 
		return;
	}

	int l = ni * 2 + 1,r = l + 1, mid = ns + (ne - ns) / 2;
	update(pos,l,ns,mid);
	update(pos,r,mid+1,ne);

	tree[ni] = merge(tree[l],tree[r]);

}



int main(void){

	fast;

	#ifdef Khaled
		freopen("in.txt","r",stdin);
		freopen("out.txt","w",stdout);
	#endif
	int ts = 1;
	while (cin >> n){
		cout << "Test " << ts++ << ":\n";
		for(int i = 0 ; i < n; ++i){
			char c;
			cin >> c;
			arr[i] = (c == ')');
		}
		build();


		cin >> q;
		while(q--){
			int x;
			cin >> x;
			if(x){
				update(--x);
			}
			else{
				cout << ((tree[0].rr == 0 && tree[0].rl == 0) ? "YES" : "NO") << endl;
			}
		}


	}




}