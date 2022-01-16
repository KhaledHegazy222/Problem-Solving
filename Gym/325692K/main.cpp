
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
	vector<int>v(n);
	for(int i = 0;i<n;i++){
		v[i] = i + 1;
	}

	do{
		for(int i = 0;i<n;i++){
			cout << v[i] << " \n"[i + 1 == n];
		}
	}while(next_permutation(all(v)));



}