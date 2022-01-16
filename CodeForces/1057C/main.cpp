#include <bits/stdc++.h>
#define fast cin.tie(0),ios::sync_with_stdio(0),cout.tie();
#define all(a) a.begin(),a.end()

typedef long long ll;
typedef unsigned long long ull;

using namespace std;

const int N = 50 + 5;
int color[N],A[N],n;

int dp[N][N][4][2000 + 5];


int solve(int idx,int lastValue,int lastColor,int rem){
	if(rem <= 0)
		return 0;
	int &ret = dp[idx][lastValue][lastColor][rem];
	if(~ret)
		return ret;


	ret = 1e5;
	for(int i = 0;i < n;i++){
		if(A[i] > lastValue && lastColor != color[i])
			ret = min(ret,abs(idx - i) + solve(i,A[i],color[i],rem - A[i]));
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
	int st,k;
	cin >> st >> k;
	for(int i = 0;i < n;i++)
		cin >> A[i];
	string s;
	cin >> s;
	string ref = "RGB";
	for(int i = 0;i < n;i++)
		color[i] = ref.find(s[i]) + 1;
	// for(int i = 0;i < n;i++)
	// 	cout << color[i] << " \n"[i + 1 == n];
	
	cout << (solve(st-1,0,0,k) < 1e4 ? solve(st-1,0,0,k)  : -1) << endl;

}


