#include <bits/stdc++.h>
#define fast cin.tie(0),ios::sync_with_stdio(0),cout.tie();
#define all(a) a.begin(),a.end()

typedef long long ll;
typedef unsigned long long ull;

using namespace std;

const int N = 10000 + 5;

int A[N],n,k;

map<pair<pair<int,int>,int>,int>dp;

int solve(int i,int j,int insertions){
	if(insertions > k)
		return 100;
	if(i >= j)
		return insertions;
	
	if(dp.find({{i,j},insertions}) != dp.end())
		return dp[{{i,j},insertions}];

	int ret = 100;
	if(A[i] == A[j])	
		ret = min(ret,solve(i + 1,j - 1,insertions));
	else{
		ret = min({ret,solve(i + 1,j,insertions + 1),solve(i,j - 1,insertions + 1)});
	}
	dp[{{i,j},insertions}] = ret;
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

	int cs = 1;
	int t;
	cin >> t;
	while(t--){
		dp.clear();
		cin >> n >> k;
		// if(n < 20)
		// 	cout << "YESSSSSS\n";
		for(int i = 0;i < n;i++){
			cin >> A[i];
		}
		int ans = solve(0,n - 1,0);
		cout << "Case " << cs++ << ": ";	
		if(ans > k){
			cout << "Too difficult\n";
		}
		else if(!ans)
			cout << "Too easy\n";
		else
			cout << ans << endl;
	}
	

}


