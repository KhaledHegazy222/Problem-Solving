
#include <bits/stdc++.h>

#define all(a) a.begin(),a.end()
#define fast cin.tie(0),ios::sync_with_stdio(0),cout.tie(0)
#define ll long long 
#define ull unsigned long long 

using namespace std;

const int N = 500;
int n,m,k;

int Mat[N][N],vis[N][N],vid;

int valid(int i,int j){
	return i >= 0 && i < n && j >= 0 && j < m;
}



int dfs(int i,int j,int remain){
	if(vis[i][j] == vid || !Mat[i][j] || !remain) return 0; 
 	vis[i][j] = vid;
	int cnt = 1;
	remain--;
	if(valid(i + 1,j)){
		int ret = dfs(i + 1,j,remain);
		remain -= ret;
		cnt += ret;
	}
		
	if(valid(i - 1,j)){
		int ret = dfs(i - 1,j,remain);
		remain -= ret;
		cnt += ret;
	}
		
	if(valid(i,j + 1)){
		int ret = dfs(i,j + 1,remain);
		remain -= ret;
		cnt += ret;
	}
		
	if(valid(i,j - 1)){
		int ret = dfs(i,j - 1,remain);
		remain -= ret;
		cnt += ret;
	}
		
	return cnt;
	
}


void explore(int cnt){
	vid++;
	for(int i = 0;i<n;i++){
		for(int j = 0;j<m;j++){
			if(Mat[i][j]){
				dfs(i,j,cnt - k );
				return;
			}
				
		}
	}
}

int main(void){	
	fast;
	#ifdef Khaled
		freopen("in.txt","r",stdin);
		//freopen("out.txt","w",stdout);
	#endif
		cin >> n >> m >> k;
		int cnt = 0;
		for(int i = 0;i<n;i++){
			for(int j = 0;j<m;j++){
				char c;
				cin >> c;
				Mat[i][j] = (c == '.');
				cnt += Mat[i][j];
			}
		}
		explore(cnt);

		for(int i = 0;i<n;i++){
			for(int j = 0;j<m;j++){
				cout << (Mat[i][j] ? (vis[i][j] == vid ? '.' : 'X') : '#');
			}
			cout << endl;
		}

	




}	