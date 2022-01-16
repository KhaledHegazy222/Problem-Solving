/*
	Created By : Khaled Hegazy
*/


#include <bits/stdc++.h>
#define all(x) x.begin(),x.end()
#define fast cin.tie(0),ios::sync_with_stdio(0),cout.tie(0)
#define PI (acos(-1))


using namespace std;

typedef unsigned long long ull;
typedef long long ll;


string s;

int mem[5001][5001];
int vis[5001][5001];



int dp(int i,int j){
	if(i >= j) return 0;

	if(vis[i][j] != 0){
		return mem[i][j];
	}

	vis[i][j] = 1;
	int &ret = mem[i][j];

	if(s[i] == s[j]){
		return ret = dp(i+1,j-1);
	}
	else{
		int ch1 = 1 + dp(i+1,j);
		int ch2 = 1 + dp(i,j-1);
		return ret = min(ch1,ch2);
	}



}



int main(void){
	fast;
	#ifdef Khaled
		freopen("out.txt","w",stdout);
		freopen("in.txt","r",stdin);
	#endif
	#ifndef Khaled
		//freopen(".in","r",stdin);
	#endif

	int n;
	cin >> n;
	cin >> s;


	cout << dp(0,n-1) << endl;


}	


