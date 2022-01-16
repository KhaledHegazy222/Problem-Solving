
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
	
	int n;
	cin >> n;
	int res = 0;
	int arr[n];
	for(int i = 0;i<n;i++){
		cin >> arr[i];
		res = __gcd(res,arr[i]);
	}

	int ttl =  (*max_element(arr,arr + n) ) / res;


	cout << ((ttl - n) % 2 ? "Alice\n" : "Bob\n");


}