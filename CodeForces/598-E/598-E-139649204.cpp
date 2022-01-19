#include <bits/stdc++.h>
#define fast cin.tie(0),ios::sync_with_stdio(0),cout.tie();
#define all(a) a.begin(),a.end()

typedef long long ll;
typedef unsigned long long ull;

using namespace std;

int dp[31][31][51];

int solve(int x,int y,int rem){
	if(!rem)
		return 0;
	if(x * y == rem)
		return 0;
	int &ret = dp[x][y][rem];
	if(~ret)
		return ret;
	ret = 1e5;
	for(int i = 1;i < x;i++){
		int cost = y * y;
		for(int j = 0;j <= min(rem,y * i);j++){
			ret = min(ret,cost + solve(i,y,j) + solve(x - i,y,rem - j));
		}
	}
	for(int i = 1;i < y;i++){
		int cost = x * x;
		for(int j = 0;j <= min(rem,x * i);j++){
			ret = min(ret,cost + solve(x,i,j) + solve(x,y - i,rem - j));
		}
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
	int t;
	cin >> t;
	while(t--){
		int x,y,k;
		cin >> x >> y >> k;
		cout << solve(x,y,k) << endl;
	}

}