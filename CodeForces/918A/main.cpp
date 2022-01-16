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
	int fib[17];
	fib[0] = fib[1] = 1;
	for(int i = 2;i<17;i++){
		fib[i] = fib[i - 1] + fib[i - 2];
	}

	int n;
	cin >> n;
	string s(n,'o');
	
	for(int i = 0;i<17;i++){
		if(fib[i] > n)
			break;
		s[fib[i] - 1] = 'O';
	}
	cout << s << endl;
	



}