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

int n,m;
string a,b;
int mem[101][101];
int vis[101][101];
int vid;

int dp(int i,int j){
	if(i == n) return m - j;
	if(j == m) return n - i;
	int &ret = mem[i][j];
	if(vis[i][j] == vid) return ret;

	vis[i][j] = vid;

	if(a[i] == b[j]) return ret = 1 + dp(i+1,j+1);

	int ch1 = 1 + dp(i+1,j);
	int ch2 = 1 + dp(i,j+1);

	return ret = min(ch1,ch2);

}


void build(int i,int j){
	if(i == n){
		cout << b.substr(j,m-j);
		return;
	} 
	if(j == m){
		cout << a.substr(i,n-i);
		return;
	}

	if(a[i] == b[j]){
		cout << a[i];
		build(i+1,j+1);
		return;
	}
	int ch1 = dp(i+1,j);
	int ch2 = dp(i,j+1);
	if(ch1 <= ch2){
		cout << a[i];
		build(i+1,j);
	}
	else{
		cout << b[j];
		build(i,j+1);
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


	while(cin >> a >> b){
		vid++;
		n = a.length();
		m = b.length();
		dp(0,0);
		build(0,0);
		cout << endl;
	}



}	


