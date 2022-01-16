#include <bits/stdc++.h>
#define fast cin.tie(0),ios::sync_with_stdio(0),cout.tie();
#define all(a) a.begin(),a.end()

typedef long long ll;
typedef unsigned long long ull;

using namespace std;



const int N = 1e5 + 5;
int A[N],B[N],C[N],n;


int dp[N][4];



int solve(int idx,int last){
	if(idx == n)
		return 0;
	
	int &ret = dp[idx][last];
	if(~ret)
		return ret;
	ret = 0;
	if(last != 1){
		ret = max(ret,A[idx] + solve(idx + 1,1));
	}
	if(last != 2){
		ret = max(ret,B[idx] + solve(idx + 1,2));
	}
	if(last != 3){
		ret = max(ret,C[idx] + solve(idx + 1,3));
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
		cin >> A[i] >> B[i] >> C[i];

	cout << solve(0,0) << endl;

}
	

