
#include <bits/stdc++.h>

#define all(a) a.begin(),a.end()
#define fast cin.tie(0),ios::sync_with_stdio(0),cout.tie(0)
#define ll long long 

using namespace std;


vector<ll>v;

void init(){
	
	for(int i = 1;i<=10;i++){
		
		int x = 0;
		while(1){

			int z = x;
			string res;
			for(int j = 0;j<i;j++){
				if(z & 1)
					res.push_back('7');
				else
					res.push_back('4');
				z >>= 1;
			}
			reverse(all(res));
			if(count(all(res),'4') == count(all(res),'7'))
				v.push_back(stoll(res));
			x++;
			if(find(all(res),'4') == res.end())
				break;
		}
	}
}






int main(void){	
	fast;
	#ifdef Khaled
		freopen("in.txt","r",stdin);
		//freopen("out.txt","w",stdout);
	#endif	


	init();
	
	ll n;
	cin >> n;
	
	cout << v[lower_bound(all(v),n ) - v.begin()] << endl; 



}