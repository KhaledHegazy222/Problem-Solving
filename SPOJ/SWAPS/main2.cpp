/*
	Created By : Khaled Hegazy
*/


#include <bits/stdc++.h>
#define all(x) x.begin(),x.end()
#define fast cin.tie(0),ios::sync_with_stdio(0),cout.tie(0)

using namespace std;

typedef unsigned long long ull;
typedef long long ll;
const int V = 50000 + 5, SQ = 500 + 5;
const int N = 250000 + 5;

int arr[N];


int n,sq;
ll ttl_inv;


struct bit2d{
	int bit[SQ][V];
	bit2d(){
		memset(bit,0,sizeof bit);
	}


	int get(int i,int j){
		int ret = 0;
		for(i++; i; i-= i & -i){
			int k = j;
			for(k++;k;k -= k & -k){
				ret += bit[i-1][k-1];
			}
		}
		return ret;
	}
	void add(int i,int j,int val){
		for(i++; i <= SQ; i+= i & -i){
			int k = j;
			for(k++;k <= V;k += k & -k){
				bit[i-1][k-1] += val;
			}
		}
	}

	int box(int stx,int sty,int enx,int eny){
		return get(enx,eny) - get(enx,sty-1) - get(stx-1,eny) + get(stx-1,sty-1);
	}


}bit2d;


void modify(int pos,int val){
	int Bid = pos / sq;
	if(arr[pos]){
		bit2d.add(Bid,arr[pos],-1);	
		ttl_inv -= bit2d.box(0,arr[pos]+1,Bid-1,V-1) + bit2d.box(Bid+1,0,sq-1,arr[pos]-1) ;
	}

	for(int i = Bid*sq;i < min(n,(Bid+1) * sq);i++){
		if((pos < i && arr[pos] > arr[i]) || (pos > i && arr[pos] < arr[i])){
			ttl_inv--;
		}
	}
	
	arr[pos] = val;
	for(int i = Bid*sq;i < min(n,(Bid+1) * sq);i++){
		if((pos < i && arr[pos] > arr[i]) || (pos > i && arr[pos] < arr[i])){
			ttl_inv++;
		}
	}
	
	
	ttl_inv += bit2d.box(0,arr[pos]+1,Bid-1,V-1) + bit2d.box(Bid+1,0,sq-1,arr[pos]-1) ;

	bit2d.add(Bid,val,1);

}






int main(void){
	fast;
	#ifdef Khaled
		freopen("out.txt","w",stdout);
		freopen("in.txt","r",stdin);
	#endif
	#ifndef Khaled
		//freopen(".in","r",stdin);
	#endif

	cin >> n;
	sq = ceil(sqrt(n));
	for(int i = 0;i<n;i++){
		int x;
		cin >> x;
		modify(i,x);
		//bit2d.add(i/sq,x,1);
	}

	int q;
	cin >> q;
	while(q--){
		int pos,val;
		cin >> pos >> val;
		pos--;
		modify(pos,val);
		cout << ttl_inv << endl;
	}



}