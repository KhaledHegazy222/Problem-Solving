#include <bits/stdc++.h>
#define fast cin.tie(0),ios::sync_with_stdio(0),cout.tie();
#define all(a) a.begin(),a.end()

typedef long long ll;
typedef unsigned long long ull;

using namespace std;

vector<ll>res;
int sz;
void solve(int idx,int rem,string &s){
	if(idx == sz){
		if(!rem)
			res.push_back(stoll(s));
		return;
	}

	if(idx){
		s.push_back('0');
		solve(idx + 1,rem,s);
		s.pop_back();
	}

	if(rem){
		for(int i = 1;i < 10;i++){
			s.push_back(i + '0');
			solve(idx + 1,rem - 1,s);
			s.pop_back();
		}
	}

}


signed main(void){

	#ifdef Khaled
		freopen("in.txt","r",stdin);
		//freopen("out.txt","w",stdout);
	#endif
	#ifndef Khaled
		#define endl '\n'
		fast;
	#endif
	string s;
	for(int i = 1;i<19;i++){
		sz = i;
		for(int j = 1;j <= min(i,3);j++)
			solve(0,j,s);
	}
	res.push_back(1000000000000000000);
	sort(all(res));
	// for(auto elem : res)
	// 	cout << elem << endl;

	int t;
	cin >> t;
	while(t--){
		ll l,r;
		cin >> l >> r;
		cout << lower_bound(all(res),r + 1) - lower_bound(all(res),l) << endl;
	}
}


