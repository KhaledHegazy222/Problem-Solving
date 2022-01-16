#include <bits/stdc++.h>
#define fast cin.tie(0),ios::sync_with_stdio(0),cout.tie();
#define all(a) a.begin(),a.end()

typedef long long ll;
typedef unsigned long long ull;

using namespace std;


const int N = 1e3 + 5;
int n,c,l;
int A[N];

int vis[N][N];
int dp[N][N];


int minLec;

int solve(int idx,int takenLec){
	
	if(idx == n){
		return (takenLec == minLec ? 0 : 1e9);
	}

	int &ret = dp[idx][takenLec];
	if(vis[idx][takenLec])
		return ret;

	vis[idx][takenLec] = 1;
	int sum = 0;
	int sol = 1e9;
	for(int i = idx;i < n;i++){
		if(sum + A[i] <= l){
			int rem = l - (sum + A[i]);
			int cost;
			if(rem > 10)
				cost = (rem - 10) * (rem - 10);
			else if(!rem)
				cost = 0;
			else
				cost = -c;
			
			sol = min(sol,cost + solve(i + 1,takenLec + 1));
		}
		else
			break;
		sum += A[i];
	}
	return ret = sol;
	
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
	int flag = 0;
	while(cin >> n,n){
		memset(vis,0,sizeof vis);
		cin >> l >> c;

		for(int i = 0;i < n;i++)
			cin >> A[i];
		minLec = 1;
		int rem = l;
		for(int i = 0;i < n;i++){
			if(rem >= A[i])
				rem -= A[i];
			else{
				minLec++;
				rem = l - A[i];
			}
		}

		if(flag)
			cout << endl;
		flag = 1;
		cout << "Case " << cs++ << ":\n";
		cout << "Minimum number of lectures: " << minLec << endl;
		cout << "Total dissatisfaction index: ";
		cout << solve(0,0) << endl;
	}

}



