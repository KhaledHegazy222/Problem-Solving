
#include <bits/stdc++.h>

#define all(a) a.begin(),a.end()
#define fast cin.tie(0),ios::sync_with_stdio(0),cout.tie(0)
#define ll long long 

using namespace std;

ll Mul(ll a,ll b,ll mod){
	if(!b) return 0;
	ll res = 0;
	while(b){
		if(b & 1)
			res = (res + a) % mod;
		b >>= 1;
		a = (a * 2) % mod;
	}
	return res;
}

ll powerMOD(ll b,ll p,ll mod){
	if(!p) return 1;

	ll res = 1;
	while(p){
		if(p & 1)
			res = Mul(res,b,mod);
		p >>= 1;
		b = Mul(b,b,mod);
	}
	return res;
}


ll mulInv(ll x,ll mod){
	return powerMOD(x,mod - 2,mod);
}

int main(void){	
	fast;
	#ifdef Khaled
		freopen("in.txt","r",stdin);
		//freopen("out.txt","w",stdout);
	#endif
	
	ll a,b,p;
	cin >> a >> b >> p;
	cout << powerMOD(a,b,p) << '\n';
	cout << Mul(a,b,p) << '\n';
	cout << Mul(a,mulInv(b,p),p) << endl;

}