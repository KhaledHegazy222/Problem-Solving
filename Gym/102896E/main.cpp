#include <bits/stdc++.h>

#define all(a) a.begin(),a.end()
#define fast cin.tie(0),ios::sync_with_stdio(0),cout.tie(0)
#define ll long long 

using namespace std;
const int N = 1e5 + 5;

int srch(deque<int>&q,int k){
	int l = 0,r = q.size() - 1;
	while(l != r){
		int m = l + (r - l + 1) / 2;
		if(q[m] > k)
			r = m - 1;
		else
			l = m;
	}
	return q[l];
}

int main(void){
	
	#ifdef Khaled
		freopen("in.txt","r",stdin);
		//freopen("out.txt","w",stdout);
    #endif	
    fast;




	int t;
	cin >> t;
	while(t--){
		ll b,d;
		cin >> b >> d;
		ll a = b / __gcd(b,d);
		cout << (b * b - 1) / (a * d) << '\n';
	}

}