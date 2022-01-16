/*
	Created By : Khaled Hegazy
*/


#include <bits/stdc++.h>
#define all(x) x.begin(),x.end()
#define fast cin.tie(0),ios::sync_with_stdio(0),cout.tie(0)

using namespace std;

typedef unsigned long long ull;
typedef long long ll;


const int N = 30000 + 5 , SQ = 174;

int sorted[N],arr[N];

int n,sq;
int query(int st,int en,int x){
	int StB = st / sq;
	int EnB = en / sq;
	int ret = 0;
	if(StB == EnB){
		for(int i = st;i<= en;i++){
			ret += arr[i] > x;
		}
	}
	else{
		for(int i = st;i < (StB+1) * sq;i++){
			ret += arr[i] > x;
		}
		for(int i = EnB*sq;i <= en;i++){
			ret += arr[i] > x;
		}
		for(int i = StB+1;i<EnB;i++){
			ret +=  (sorted + (i+1) * sq) -  lower_bound(sorted + i * sq, sorted + (i+1) * sq,x + 1) ;
		}
	}
	return ret;

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
	for(int i = 0;i<n;i+=sq){
		int k = 0;
		for(;k < sq && i + k < n;k++){			
			cin >> arr[i+k];
			sorted[i+k] = arr[i+k];
		}	
		sort(sorted + i,sorted + i + k);
	}

	
	int q;
	cin >> q;
	while(q--){
		int i,j,k;
		cin >> i >> j >> k;
		cout << query(--i,--j,k) << endl;
	}




	
}
