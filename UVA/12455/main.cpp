
#include <bits/stdc++.h>

#define all(a) a.begin(),a.end()
#define fast cin.tie(0),ios::sync_with_stdio(0),cout.tie(0)
#define ll long long 

using namespace std;
int n,x;
int current;
vector<int>len;
int res = 0;
bool solve(int idx){
	if(idx == n)
		return (current == x);
	
	current += len[idx];
	int ch1 = solve(idx + 1);
	current -= len[idx];
	int ch2 = solve(idx + 1);

	return ch1 || ch2;
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
		cin >> x >> n;
		len.resize(n);
		for(int i = 0;i<n;i++){
			cin >> len[i];
		}
		cout << (solve(0) ? "YES\n" : "NO\n");
	}
}