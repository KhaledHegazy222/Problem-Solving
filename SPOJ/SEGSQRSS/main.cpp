	/*
		Created By : Khaled Hegazy
	*/


	#include <bits/stdc++.h>

	#define all(a) a.begin(),a.end()
	#define fast cin.tie(0),ios::sync_with_stdio(0),cout.tie(0)
	#define ll long long 

	using namespace std;

	const int N = 1e6 + 5;


	int n,q,arr[N];


	struct node{
		ll sum,sumSQ,lazy;
		int lazyType;

		void modifyS(int val,int ni,int ns,int ne){
			lazyType = 1; // Set Lazy
			sum = 1ll * val * (ne - ns + 1);
			sumSQ = 1ll * val * val * (ne - ns + 1);
			lazy = val;
		}

		void modifyI(int val,int ni,int ns,int ne){
			lazyType = 2;
			sumSQ += 2 * sum * val + (ne - ns +  1) * 1ll * val * val;
			sum += 1ll * (ne - ns + 1) * val;
			lazy += val;
		}


	}tree[N << 1];


	node merge(node &l,node &r){
		node ret;
		ret.sum = l.sum + r.sum;
		ret.sumSQ = l.sumSQ + r.sumSQ;
		ret.lazy = ret.lazyType = 0;
		return ret;
	}


	void pushDown(int ni,int ns,int ne){
		if(!tree[ni].lazyType || ns == ne) return;

		int l = ni * 2 + 1,r = l + 1,mid = ns + (ne - ns) / 2;

		if(tree[ni].lazyType == 1){ // Set Lazy

			tree[l].modifyS(tree[ni].lazy,l,ns,mid);
			tree[r].modifyS(tree[ni].lazy,r,mid+1,ne);
			tree[ni] = merge(tree[l],tree[r]);

		}
		else{ // Inc Lazy
			tree[l].modifyI(tree[ni].lazy,l,ns,mid);
			tree[r].modifyI(tree[ni].lazy,r,mid+1,ne);
			tree[ni] = merge(tree[l],tree[r]);
		}


	}



	void build(int ni = 0,int ns = 0,int ne = n - 1){
		if(ns == ne){
			tree[ni] = {arr[ns],1ll * arr[ns] * arr[ns],0,0};
			return;
		}

		int l = ni * 2 + 1,r = l + 1,mid = ns + (ne - ns) / 2;

		build(l,ns,mid);
		build(r,mid+1,ne);

		tree[ni] = merge(tree[l],tree[r]);


	}


	ll query(int qs,int qe,int ni = 0,int ns = 0,int ne = n - 1){
		
		if(ns > qe || ne < qs) return 0;
		if(ns >= qs && ne <= qe) return tree[ni].sumSQ;

		int l = ni * 2 + 1,r = l + 1,mid = ns + (ne - ns) / 2;
		pushDown(ni,ns,ne);

		return query(qs,qe,l,ns,mid) + query(qs,qe,r,mid + 1,ne);
	}





	// 0 No Lazy
	// 1 Set Lazy
	// 2 Inc Lazy

	void Set(int qs,int qe,int val,int ni = 0,int ns = 0,int ne = n - 1){
		if(qs > ne || qe < ns) return;

		if(ns >= qs && ne <= qe) {
			tree[ni].modifyS(val,ni,ns,ne);
			return;
		}

		pushDown(ni,ns,ne);
			
		int l = ni * 2 + 1,r = l + 1,mid = ns + (ne - ns) / 2;



		Set(qs,qe,val,l,ns,mid);
		Set(qs,qe,val,r,mid+1,ne);
		tree[ni] = merge(tree[l],tree[r]);


	}



	void Inc(int qs,int qe,int val,int ni = 0,int ns = 0,int ne = n - 1){
		if(ns > qe || ne < qs) return;
		
		if(ns >= qs && ne <= qe){
			tree[ni].modifyI(val,ni,ns,ne);
			return;
		}

		pushDown(ni,ns,ne);
		int l = ni * 2 + 1,r = l + 1,mid = ns + (ne - ns) / 2;


		Inc(qs,qe,val,l,ns,mid);
		Inc(qs,qe,val,r,mid+1,ne);

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
			for(int i = 0;i < n;i++){
				cin >> arr[i];
			}
			build();
			while(q--){
				int type,st,en;;
				cin >> type >> st >> en;
				st--,en--;
				if(!type){
					int val;
					cin >> val;
					Set(st,en,val);  
				}
				else if(type == 1){
					int val;
					cin >> val;
					Inc(st,en,val);
				}
				else{
					cout << query(st,en) << endl;
				}
				
			}

		}

	}



