
#include <bits/stdc++.h>

#define all(a) a.begin(),a.end()
#define fast cin.tie(0),ios::sync_with_stdio(0),cout.tie(0)
#define ll long long 

using namespace std;

void fun(int n){
	int x = 0;
	while(1){
		int z = x;
		string res;
		for(int j = 0;j<n;j++){
			if(z & 1)
				res.push_back('1');
			else
				res.push_back('0');
			z >>= 1;
		}
		reverse(all(res));

		if(count(res.begin(),res.begin() + n / 2,'1') == count(res.begin() + n / 2,res.end(),'1'))
			cout << res << endl;
		x++;
		if(count(all(res),'0') == 0)
			break;
	}
}



int main(void){	
	fast;
	#ifdef Khaled
		freopen("in.txt","r",stdin);
		//freopen("out.txt","w",stdout);
	#endif	


	int t;
	cin >> t;
	while(t--){
		int n;
		cin >> n;
		fun(2 * n);
	}

}