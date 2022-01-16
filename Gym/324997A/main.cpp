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
	int current = n;
	int len = 1;
	while(current != 1){
		if(current % 2)
			current = current * 3 + 1;
		else
			current = current / 2;
		len++;
	}
	cout << len << endl;



}