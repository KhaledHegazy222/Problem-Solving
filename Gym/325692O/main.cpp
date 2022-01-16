
#include <bits/stdc++.h>

#define all(a) a.begin(),a.end()
#define fast cin.tie(0),ios::sync_with_stdio(0),cout.tie(0)
#define ll long long 

using namespace std;
const int N = 10;
int Mat[N][N],vis[N][N];
int res;

int n,m;

int valid(int i,int j){
	return i >= 0 && i < n && j >= 0 && j < m;
}


void bk(int i,int j){
	if(i == n-1 && j == m - 1){
		res++;
		return;
	}
	if(vis[i][j]) return;

	
	vis[i][j] = 1;

	if(valid(i + 1,j) && Mat[i+1][j] == 1){
		bk(i+1,j);
	}
	if(valid(i,j+1) && Mat[i][j + 1] == 1){
		bk(i,j+1);
	}
	if(valid(i-1,j) && Mat[i-1][j] == 1){
		bk(i-1,j);
	}
	if(valid(i,j-1) && Mat[i][j - 1] == 1){
		bk(i,j-1);
	}

	vis[i][j] = 0;
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
			cin >> Mat[i][j];
		}
	}
	bk(0,0);
	cout << res << endl;



}