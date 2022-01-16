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
	for(int i = 0;i<n;i++){
		string space(n - i - 1,' ');
		string star(2*i + 1,'*');
		cout << space << star << '\n';
 	}





}