/*
	Created By : Khaled Hegazy
*/


#include <bits/stdc++.h>


#define fast cin.tie(0),ios::sync_with_stdio(0),cout.tie(0)

using namespace std;

const int N = 1 << 17;
int n;


struct node{
	int maxi,maxii;
}tree[N << 1];

int arr[N];





void build(int ni = 0,int ns = 0,int ne = n - 1){

	if(ns == ne){
		tree[ni].maxi = arr[ns];
		tree[ni].maxii = 0;
		return;
	}
	int l = ni * 2 + 1;
	int r = l + 1;
	int mid = ns + (ne - ns) / 2;
	build(l,ns,mid);
	build(r,mid+1,ne);
	int sorted[4] = {tree[l].maxi,tree[l].maxii,tree[r].maxi,tree[r].maxii};
	sort(sorted,sorted + 4);
	tree[ni].maxi = sorted[3];
	tree[ni].maxii = sorted[2];

	

}

pair<int,int> query(int qs,int qe,int ni = 0,int ns = 0,int ne = n - 1){
	if(qs > ne || qe < ns) return {0,0};
	if(ns >= qs && ne <= qe) return {tree[ni].maxi,tree[ni].maxii};
	int l = ni * 2 + 1;
	int r = l + 1;
	int mid = ns + (ne - ns) / 2;
	auto r1 = query(qs,qe,l,ns,mid),r2 =  query(qs,qe,r,mid+1,ne);
	int sorted[4] = {r1.first,r1.second,r2.first,r2.second};
	sort(sorted,sorted + 4);
	return {sorted[3],sorted[2]};




}


void update(int pos,int val,int ni = 0,int ns = 0,int ne = n - 1){
	if(ns > pos || ne < pos) return;
	if(ns == ne){
		arr[ns] = val;
		tree[ni].maxi = val;
		tree[ni].maxii = 0;
		return;
	}
	int l = ni * 2 + 1;
	int r = l + 1;
	int mid = ns + (ne - ns) / 2;
	update(pos,val,l,ns,mid);
	update(pos,val,r,mid+1,ne);
	int sorted[4] = {tree[l].maxi,tree[l].maxii,tree[r].maxi,tree[r].maxii};
	sort(sorted,sorted + 4);
	tree[ni].maxi = sorted[3];
	tree[ni].maxii = sorted[2];
}




int main(void){
	//fast;


	#ifdef Khaled 
		freopen("in.txt","r",stdin);
		freopen("out.txt","w",stdout);
	#endif

	scanf("%d",&n);
	for(int i = 0;i<n;i++){
		scanf("%d",arr + i);
	}
	build();


	int q;
	scanf("%d",&q);
	while(q--){
		char type;
		int i,j;
		scanf(" %c %d %d",&type,&i,&j);
		if(type == 'U'){
			update(--i,j);
		}
		else{
			auto ret = query(--i,--j);
			printf("%d\n",ret.first + ret.second);
		}
		
	}




}