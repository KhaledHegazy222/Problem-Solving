
#include <bits/stdc++.h>

#define all(a) a.begin(),a.end()
#define fast cin.tie(0),ios::sync_with_stdio(0),cout.tie(0)
#define ll long long 

using namespace std;


int n;
vector<int>v;


bool sol(int idx,int deg){
	if(idx == n)
		return !deg;
	
	return sol(idx + 1,(deg + v[idx]) % 360) || sol(idx + 1,(deg - v[idx] + 360) % 360);
}

int main(void){	
	fast;
	#ifdef Khaled
		freopen("in.txt","r",stdin);
		//freopen("out.txt","w",stdout);
	#endif	


	cin >> n;
	v.resize(n);
	for(int i = 0;i<n;i++){
		cin >> v[i];
	}

	cout << (sol(0,0) ? "YES\n" : "NO\n");






}