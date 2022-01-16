#include <bits/stdc++.h>

#define all(a) a.begin(),a.end()
#define fast cin.tie(0),ios::sync_with_stdio(0),cout.tie(0)
#define ll long long 
#define MOD 1000000007

using namespace std;
const int N = 1e3 + 5;
int Mat[N][N];
int vis[N][N];
int n,m;



int valid(int i,int j){
	return i >= 0 && i < n && j >= 0 && j < m;
}


void dfs(int i,int j){
	if(vis[i][j])
		return;
	vis[i][j] = 1;
	if(valid(i+1,j) && Mat[i+1][j] == Mat[i][j])
		dfs(i+1,j);
	if(valid(i-1,j) && Mat[i-1][j] == Mat[i][j])
		dfs(i-1,j);
	if(valid(i,j+1) && Mat[i][j+1] == Mat[i][j])
		dfs(i,j+1);
	if(valid(i,j-1) && Mat[i][j-1] == Mat[i][j])
		dfs(i,j-1);
}




int main(void){	
	fast;
	#ifdef Khaled
		freopen("in.txt","r",stdin);
		//freopen("out.txt","w",stdout);
	#endif	

	cin >> n >> m;
	for(int i = 0;i<n;i++){
		for(int j = 0;j<m;j++){
			char x;
			cin >> x;
			Mat[i][j] = (int) x;
		}
	}
	int cc = 0;
	for(int i = 0;i<n;i++){
		for(int j = 0;j<m;j++){
			if(!vis[i][j]){
				cc++;
				dfs(i,j);
			}
		}
	}
	cout << cc << endl;

}