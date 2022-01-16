#include <bits/stdc++.h>
#define fast cin.tie(0),ios::sync_with_stdio(0),cout.tie();
#define all(a) a.begin(),a.end()

typedef long long ll;
typedef unsigned long long ull;

using namespace std;

map<vector<vector<char>>,int>dp;

int win(vector<vector<char>>game){
	if(game[0][0] == game[0][1] && game[0][1] == game[0][2] && game[0][0] != '.') return 1;
	if(game[1][0] == game[1][1] && game[1][1] == game[1][2] && game[1][0] != '.') return 1;
	if(game[2][0] == game[2][1] && game[2][1] == game[2][2] && game[2][0] != '.') return 1;

	if(game[0][0] == game[1][0] && game[1][0] == game[2][0] && game[0][0] != '.') return 1;
	if(game[0][1] == game[1][1] && game[1][1] == game[2][1] && game[0][1] != '.') return 1;
	if(game[0][2] == game[1][2] && game[1][2] == game[2][2] && game[0][2] != '.') return 1;

	if(game[0][0] == game[1][1] && game[1][1] == game[2][2] && game[0][0] != '.') return 1;
	if(game[0][2] == game[1][1] && game[1][1] == game[2][0] && game[0][2] != '.') return 1;

	return 0;
}

vector<vector<char>>grid(3,vector<char>(3));

int solve(vector<vector<char>>&currentGame,int move){
	if(currentGame == grid)
		return 1;
	if(win(currentGame))
		return 0;
	if(dp.find(currentGame) != dp.end())
		return dp[currentGame];
	
	int res = 0;
	for(int i = 0;i < 3;i++){
		for(int j = 0;j < 3;j++){
			if(currentGame[i][j] == '.'){
				if(move){
					currentGame[i][j] = 'X';
				}
				else{
					currentGame[i][j] = 'O';
				}
				res |= solve(currentGame,!move);
				if(res){
					i = 3;
					j = 3;
					break;
				}
				currentGame[i][j] = '.';
			}
		}
	}
	dp[currentGame] = res;
	return res;
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
		for(int i = 0;i < 3;i++){
			for(int j = 0;j < 3;j++)
				cin >> grid[i][j];
		}
		dp.clear();
		vector<vector<char>>v(3,vector<char>(3,'.'));
		cout << (solve(v,1) ? "yes\n" : "no\n");
	}

}


