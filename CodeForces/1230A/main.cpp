
#include <bits/stdc++.h>

#define all(a) a.begin(),a.end()
#define fast cin.tie(0),ios::sync_with_stdio(0),cout.tie(0)
#define ll long long 
#define ull unsigned long long 

using namespace std;

int sum;
vector<int>v(4);

int bk(int idx = 0,int ttl = 0){
	if(idx == 4)
		return ttl << 1 == sum;

	return bk(idx+1,ttl + v[idx]) || bk(idx + 1,ttl);
}

int main(void){	
	//fast;
	#ifdef Khaled
		freopen("in.txt","r",stdin);
		//freopen("out.txt","w",stdout);
	#endif
	
	for(int i = 0;i<4;i++){
		cin >> v[i];
		sum += v[i];
	}

	cout << (bk() ? "YES\n" : "NO\n");





}	