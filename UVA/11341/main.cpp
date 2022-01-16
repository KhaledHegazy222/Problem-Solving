#include <bits/stdc++.h>
#define fast cin.tie(0),ios::sync_with_stdio(0),cout.tie();
#define all(a) a.begin(),a.end()

typedef long long ll;
typedef unsigned long long ull;

using namespace std;

const int N = 10 + 2,M = 1e2 + 5;

int L[N][M],n,m;

int dp[N][M];


int solve(int idx,int rem){
	if(idx == n)
		return 0;
	int &ret = dp[idx][rem];
	if(~ret)
		return ret;

	ret = -1e9;
	for(int i = 0;i < m;i++){
		if(rem >= i + 1 && L[idx][i] >= 5)
			ret = max(ret,L[idx][i] + solve(idx + 1,rem - i - 1));
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
	int t;
	cin >> t;
	while(t--){
		memset(dp,-1,sizeof dp);
		cin >> n >> m;
		for(int i = 0;i < n;i++){
			for(int j = 0;j < m;j++)
				cin >> L[i][j];
		}
		int res = solve(0,m);
		if(res > 0){
			cout << "Maximal possible average mark - ";
			cout << fixed << setprecision(2) << (res * 1.0 + 0.001) / n << ".\n";
		}
		else{
			// cout << "Peter, you shouldn’t have play ed billiard that much.\n";
			cout << "Peter, you shouldn't have played billiard that much.\n";
		}
	}	


}


