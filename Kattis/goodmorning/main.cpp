
#include <bits/stdc++.h>

#define all(a) a.begin(),a.end()
#define fast cin.tie(0),ios::sync_with_stdio(0),cout.tie(0)
#define ll long long 

using namespace std;

int k;
int valid[5][4] = {{1,1,1,0},{1,1,1,0},{1,1,1,0},{0,1,0,0},{0,0,0,0}};
int pad[5][4] = {{1,2,3,0},{4,5,6,0},{7,8,9,0},{0,0,0,0},{0,0,0,0}};
string res;
int dp(int i,int j,int cnt){
	if(!valid[i][j] || cnt == 4){
		if(res.size())
			return stoi(res);	
		return 0;
	}
	int ch1 = dp(i + 1,j,cnt);
	int ch2 = dp(i,j + 1,cnt);
	res.push_back(pad[i][j] + '0');
	int ch3 = dp(i,j,cnt + 1);
	res.pop_back();

	int a1 = abs(ch1 - k);
	int a2 = abs(ch2 - k);
	int a3 = abs(ch3 - k);
	int x = min({a1,a2,a3});
	if(x == a1)
		return ch1;
	if(x == a2)
		return ch2;
	return ch3;
	
		
}



int main(void){
    fast;
	#ifdef Khaled
		freopen("in.txt","r",stdin);
		//freopen("out.txt","w",stdout);
    #endif

	int t;
	cin >> t;
	while(t--){
		cin >> k;
		cout << dp(0,0,0) << '\n';
	}


}