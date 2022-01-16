
#include <bits/stdc++.h>

#define all(a) a.begin(),a.end()
#define fast cin.tie(0),ios::sync_with_stdio(0),cout.tie(0)
#define ll long long 

using namespace std;



int main(void){	
	fast;
	#ifdef Khaled
		freopen("in.txt","r",stdin);
		//freopen("out.txt","w",stdout);
	#endif

	ll n,k;
	cin >> n >> k;
	int frq[63] = {0};
	ll arr[n];
	for(ll &elem : arr){
		cin >> elem;
		ll x = elem;
		int i = 0;
		while(x){
			if(x & 1ll)
				frq[i]++;
			x >>= 1;
			i++;
		}
	}


	ll x = 0;
	for(int i = 62;i>=0;i--){
		ll y = x + (1ll << i);
		if(n - frq[i] > frq[i] && y <= k){
			frq[i] = n - frq[i];
			x += (1ll << i);
		}
	}

	ll res = 0;
	for(int i = 62;i>=0;i--){
		res += frq[i] * (1ll<<i);
	}

	cout << res << endl;





}	