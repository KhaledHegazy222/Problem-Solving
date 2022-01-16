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




int main(void){
	fast;
	#ifdef Khaled
		freopen("out.txt","w",stdout);
		freopen("in.txt","r",stdin);
	#endif
	#ifndef Khaled
		//freopen(".in","r",stdin);
	#endif	

	int n;
	cin >> n;
	cin.ignore();
	while(n--){
		vector<int>v;
		string line;
		getline(cin,line);
		stringstream ss(line);
		int num;
		while(ss >> num){
			v.push_back(num);
		}

		int mx = 0;
		for(int i = 0;i<v.size();i++){
			for(int j = i+1;j<v.size();j++){
				mx = max(mx,__gcd(v[i],v[j]));
			}
		}
		cout << mx << '\n';


	}


}	


