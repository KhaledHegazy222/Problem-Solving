/*
	Created By : Khaled Hegazy
*/


#include <bits/stdc++.h>
#define all(x) x.begin(),x.end()
#define fast cin.tie(0),ios::sync_with_stdio(0),cout.tie(0)
#define PI (acos(-1))


using namespace std;

typedef unsigned long long ull;
typedef long long ll;

vector<int>dev;



void gen_dev(int x){
	dev.push_back(1);
	if(x == 1) return;
	dev.push_back(x);

	for(int i = 2;i<= x/i;i++){
		if(x % i == 0){
			dev.push_back(i);
			if(x/i != i) dev.push_back(x/i);
		}
	}

	sort(all(dev));

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


	int a,b;
	cin >> a >> b;
	int g = __gcd(a,b);
	gen_dev(g);

	int q;
	cin >> q;

	while(q--){
		int l,r;
		cin >> l >> r;
		int ming,maxg;
		int low = 0;
		int high = dev.size()-1;
		while(high != low){
			int mid = low + (high-low+1)/2;
			if(dev[mid] <= r)
				low = mid;
			else
				high = mid - 1; 
		}
		int upper = -1;
		if(g % dev[low]==0 && dev[low] >= l) upper = dev[low];




		if(upper == -1) cout << -1 << endl;
		else	cout << dev[low] << endl;

	}



}	


