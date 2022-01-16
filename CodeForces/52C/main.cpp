/*
	Created By : Khaled Hegazy
*/


#include <bits/stdc++.h>

#define all(a) a.begin(),a.end()
#define fast cin.tie(0),ios::sync_with_stdio(0),cout.tie(0)
#define ll long long 

using namespace std;
const int N = 1 << 18;


struct node{ 
	ll min,lazy;
	bool hasLazy;

	void modify(int val,int ni,int ns,int ne){
		hasLazy = 1;
		min += val;
		lazy += val;
	}
}tree[ N << 1];

int arr[N];
int n,q;



node merge(node &a,node &b){
	node ret;
	ret.min = min(a.min,b.min);
	ret.lazy = 0;
	ret.hasLazy = 0;
	return ret;
}

void push_down(int ni,int ns,int ne){
	if(!tree[ni].hasLazy || ns == ne) return;
	
	int l = ni * 2 + 1,r = l + 1,mid = ns + (ne - ns) / 2;
	tree[l].modify(tree[ni].lazy,l,ns,mid);
	tree[r].modify(tree[ni].lazy,r,mid+1,ne);
	tree[ni] = merge(tree[l],tree[r]);
}


void build(int ni = 0,int ns = 0,int ne = n-1){

	if(ne == ns){
		tree[ni] = {arr[ns],0,false};
		return;
	}


	int l = ni * 2 + 1,r = l + 1,mid = ns + (ne - ns) / 2;

	build(l,ns,mid);
	build(r,mid+1,ne);

	tree[ni] = merge(tree[l],tree[r]);

}


ll query(int qs,int qe,int ni = 0,int ns = 0,int ne = n - 1){
	if(qs > ne || ns > qe) return 1e9;
	if(ns >= qs && ne <= qe) return tree[ni].min;

	push_down(ni,ns,ne);

	int l = ni * 2 + 1,r = l + 1,mid = ns + (ne - ns) / 2;
	return min(query(qs,qe,l,ns,mid),query(qs,qe,r,mid+1,ne));
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

	cin >> n;
	for(int i = 0;i<n;++i){
		cin >> arr[i];
	}
	build();
	cin >> q;
	cin.ignore();
	while(q--){
		string line;
		getline(cin,line);
		stringstream ss(line);
		int lf,rt;
		ss >> lf >> rt;
		if(count(all(line),' ') == 2){
			int val;
			ss >> val;
			if(lf > rt){
				update(lf,n-1,val);
				update(0,rt,val);
			}
			else{
				update(lf,rt,val);
			}
		}
		else{
			if(lf > rt){
				cout << min(query(lf,n-1) , query(0,rt)) << endl;
			}
			else{
				cout << query(lf,rt)<< endl;
			}
		}
	}


}