#include <bits/stdc++.h>
#define fast cin.tie(0),ios::sync_with_stdio(0),cout.tie();
#define all(a) a.begin(),a.end()

typedef long long ll;
typedef unsigned long long ull;

using namespace std;

signed main(void){

	#ifdef Khaled
		freopen("in.txt","r",stdin);
		//freopen("out.txt","w",stdout);
	#endif
	#ifndef Khaled
		#define endl '\n'
		fast;
	#endif

	ll cs = 1;

	ll t;
	cin >> t;
	while(t--){

		ll n;
		cin >> n;
		n--;
		vector<ll>v(n);
		for(ll i = 0;i < n;i++){
			cin >> v[i];
		}

		ll st = 0,en = 0;
		ll mxSt = -1,mxEn = -1;
		ll mx = 0;
		ll sum = 0;
		for(ll i = 0;i < n;i++){
			sum += v[en++];
			if(sum == mx){
				if(en - 1 - st > mxEn - mxSt){
					mxSt = st;
					mxEn = en - 1;
				}
				mx = sum;
			}
			
			if(sum > mx){
				mxSt = st;
				mxEn = en - 1;
				mx = sum;
			}
			if(sum < 0){
				sum = 0;
				st = en;
			}
		}
		if(~mxSt)
			cout << "The nicest part of route " << cs++ << " is between stops " << mxSt + 1 << " and " << mxEn + 2 << "\n";
		else
			cout << "Route " << cs++ << " has no nice parts\n";
	}	

}


