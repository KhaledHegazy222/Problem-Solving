#include <bits/stdc++.h>

#define all(a) a.begin(),a.end()
#define fast cin.tie(0),ios::sync_with_stdio(0),cout.tie(0)
#define ll long long 
#define MOD 1000000007

using namespace std;




int main(void){	
	fast;
	#ifdef Khaled
		freopen("in.txt","r",stdin);
		//freopen("out.txt","w",stdout);
	#endif	



	int n;
	cin >> n;
	int arr[n];
	map<int,int>mp;
	for(int i = 0;i<n;i++){
		cin >> arr[i];
		mp[arr[i]] = i + 1;
	}

	int q;
	cin >> q;
	while(q--){
		int x;
		cin >> x;
		int idx = mp[x];
		cout << (idx != 0 ? idx : -1 ) << endl; 

	}

}