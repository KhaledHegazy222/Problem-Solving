#include <bits/stdc++.h>

#define all(a) a.begin(),a.end()
#define fast cin.tie(0),ios::sync_with_stdio(0),cout.tie(0)
#define ll long long 
#define MOD 1000000007

using namespace std;




ll powerMOD(ll b,ll p){
	if(!p) return 1;
	ll res = 1;
	while(p){
		if(p & 1)
			res = ((res % MOD) * (b % MOD)) % MOD;
		b = ((b % MOD) * (b % MOD)) % MOD;
		p >>= 1;
	}
	return res;
}


int main(void){	
	fast;
	#ifdef Khaled
		freopen("in.txt","r",stdin);
		//freopen("out.txt","w",stdout);
	#endif	

	ll b,p;
	cin >>  b >> p;
	cout << powerMOD(b,p) << endl;

}