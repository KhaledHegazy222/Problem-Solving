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


int have[3];
int price[3];
int need[3];
ll money;

int valid(ll x){
	ll cost = 0;
	for(int i = 0;i<3;i++){
		if(1ll * x * need[i] >= have[i])
			cost += ( 1ll * x * need[i] - have[i] ) * price[i]; 
	}
	return cost <= money;
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



	string s;
	cin >> s;
	for(int i = 0;i<s.size();i++){
		if(s[i] == 'B'){
			need[0]++;
		}
		else if(s[i] == 'S'){
			need[1]++;
		}	
		else{
			need[2]++;
		}
	}
	cin >> have[0] >> have[1] >> have[2];
	cin >> price[0] >> price[1] >> price[2];
	cin >> money;

	ll l = 0;
	ll r = 1e15;

	while(l != r){
		ll mid = l + (r-l+1)/2;
		if(valid(mid)) l = mid;
		else r = mid-1;
	}
	cout << l << '\n';




}	


