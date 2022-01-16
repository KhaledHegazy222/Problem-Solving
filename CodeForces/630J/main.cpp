
#include <bits/stdc++.h>

#define all(a) a.begin(),a.end()
#define fast cin.tie(0),ios::sync_with_stdio(0),cout.tie(0)
#define ll long long 

using namespace std;

int lcm(int a,int b){
	return a/__gcd(a,b) * b;
}


int main(void){	
	fast;
	#ifdef Khaled
		freopen("in.txt","r",stdin);
		//freopen("out.txt","w",stdout);
	#endif
	int res = 1;
	for(int i = 2;i<=10;i++){
		res = lcm(res,i);
	}
	ll n;
	cin >> n;
	cout << n / res << endl;
}	