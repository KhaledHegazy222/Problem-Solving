#include <bits/stdc++.h>
#define fast cin.tie(0),ios::sync_with_stdio(0),cout.tie();
#define all(a) a.begin(),a.end()

typedef long long ll;
typedef unsigned long long ull;

using namespace std;
const int N = 50 + 5;
int n,m;
char grid[N][N];
int vis[N][N];

int valid(int x,int y){
	return x >= 0 && y >= 0 && x < n && y < m;
}

int dx[] = {0,1,0,-1};
int dy[] = {1,0,-1,0};


int solve(int x,int y){
	if(vis[x][y] || grid[x][y] == '#')
		return 0;
	
	vis[x][y] = 1;
	int ret = (grid[x][y] == 'G');
	for(int i = 0;i < 4;i++){
		int xx = x + dx[i];
		int yy = y + dy[i];
		if(!valid(xx,yy))
			continue;
		if(grid[xx][yy] == 'T')
			return ret;
	}
	for(int i = 0;i < 4;i++){
		int xx = x + dx[i];
		int yy = y + dy[i];
		if(!valid(xx,yy))
			continue;
		ret += solve(xx,yy);
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
	while(cin >> n >> m){
		swap(n,m);
		memset(vis,0,sizeof vis);

		int x,y;
		for(int i = 0; i< n;i++){
			for(int j= 0;j < m;j++){
				cin >> grid[i][j];
				if(grid[i][j] == 'P')	
					x = i,y = j;
			}
		}
		cout << solve(x,y) << endl;
	}

}


