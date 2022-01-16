
#include <bits/stdc++.h>

#define all(a) a.begin(),a.end()
#define fast cin.tie(0),ios::sync_with_stdio(0),cout.tie(0)
#define ll long long 
#define ull unsigned long long 

using namespace std;
int main(void){	
	//fast;
	#ifdef Khaled
		freopen("in.txt","r",stdin);
		//freopen("out.txt","w",stdout);
	#endif
	

	int n;
	cin >> n;
	int res = 0;
	for(int i = 0;i<n*n;i++){
		int x;
		cin >> x;
		res += x;

	}
	cout << res / 2 << endl;



}	