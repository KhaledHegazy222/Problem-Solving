#include <bits/stdc++.h>
#define fast cin.tie(0),ios::sync_with_stdio(0),cout.tie();
#define all(a) a.begin(),a.end()

typedef long long ll;
typedef unsigned long long ull;

using namespace std;



const int N = 1e5 + 5;

int h[N],n;
int dp[N];

int solve(int idx){
	if(idx == n - 1)
		return 0;
	
	int &ret = dp[idx];
	if(~ret)
		return ret;
	ret = INT_MAX;

	if(idx + 1 < n){
		ret = min(ret,abs(h[idx] - h[idx + 1]) + solve(idx + 1));
	}
	if(idx + 2 < n){

		ret = min(ret,abs(h[idx] - h[idx + 2]) + solve(idx + 2));
	}

	return ret;
}



signed main(void){

	#ifdef Khaled
		freopen("in.txt","r",stdin);
		//freopen("out.txt","w",stdout);
	#endif
	#ifndef Khaled
		#define endl '\n'
		fast;
	#endif
	memset(dp,-1,sizeof dp);
	cin >> n;
	for(int i = 0;i < n;i++)
		cin >> h[i];
	cout << solve(0) << endl;

}
	

