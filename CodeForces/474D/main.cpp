#include <bits/stdc++.h>
#define fast cin.tie(0),ios::sync_with_stdio(0),cout.tie();
#define all(a) a.begin(),a.end()

typedef long long ll;
typedef unsigned long long ull;

using namespace std;

int MOD = 1e9 + 7;
const int N = 1e5 + 5;
int k;

int dp[N];

int solve(int rem){
	if(!rem)
		return 1;
	int &ret = dp[rem];
	if(~ret)
		return ret;
	int ch1 = solve(rem - 1);
	int ch2 = 0;
	if(rem >= k)
		ch2 = solve(rem - k);
	return ret = (0ll + ch1 + ch2) % MOD;
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
	cin >> t >> k;
	int com[N + 1] = {0};
	for(int i = 0;i < N - 2;i++)
		com[i] = solve(i);
	for(int i = 1;i < N - 2;i++){
		com[i] = (0ll + com[i] + com[i - 1]) % MOD;

	}




	while(t--){
		int l,r;
		cin >> l >> r;
		cout << (0ll + com[r] - com[l - 1] + MOD) % MOD << endl;
	}

}


