/*
	Created By : Khaled Hegazy
*/


#include <bits/stdc++.h>


#define fast cin.tie(0),ios::sync_with_stdio(0),cout.tie(0)

using namespace std;

const int N = 1 << 17;
int n;

int arr[N],tree[N << 1];


void build(int ni = 0,int ns = 0,int ne = n-1,int OR = 0){ 
	if(ns == ne){
		tree[ni] = arr[ns];
		return;
	}

	int l = ni * 2 + 1;
	int r = l + 1;
	int mid = ns + (ne - ns) / 2;

	build(l,ns,mid,!OR);
	build(r,mid+1,ne,!OR);

	if(OR){
		tree[ni] = tree[l] | tree[r];
	}
	else{
		tree[ni] = tree[l] ^ tree[r];
	}
}



void update(int pos,int val,int ni = 0,int ns = 0,int ne = n-1,int OR = 0){
	if(ns > pos || ne < pos) return;
	if(ns == ne) {
		tree[ni] = val; 
		return;
	}


	int l = ni * 2 + 1;
	int r = l + 1;
	int mid = ns + (ne - ns) / 2;

	update(pos,val,l,ns,mid,!OR);
	update(pos,val,r,mid+1,ne,!OR);
	if(OR){
		tree[ni] = tree[l] | tree[r];
	}
	else {
		tree[ni] = tree[l] ^ tree[r];
	}


}


int main(void){
	fast;


	#ifdef Khaled 
		freopen("in.txt","r",stdin);
		freopen("out.txt","w",stdout);
	#endif

	
	int q;
	cin >> n >> q;

	int x = n % 2;
	n = 1 << n;

	
	for(int i = 0;i<n;i++){
		cin >> arr[i];
	}


	build(0,0,n-1,x);


	while(q--){
		int pos,val;
		cin >> pos >> val;
		update(--pos,val,0,0,n-1,x);
		cout << tree[0] << endl;
	}


}