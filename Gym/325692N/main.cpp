#include <bits/stdc++.h>

#define all(a) a.begin(),a.end()
#define fast cin.tie(0),ios::sync_with_stdio(0),cout.tie(0)
#define ll long long 

using namespace std;
const int N = 10;
int Mat[N][N];
vector<int>path;

set<vector<int>>st;


int n,m;

int valid(int i,int j){
	return i >= 0 && i < n && j >= 0 && j < m;
}


void bk(int i,int j){
	if(i == n-1 && j == m - 1){
		st.insert(path);
	}

	if(valid(i + 1,j)){
		path.push_back(Mat[i + 1][j]);
		bk(i+1,j);
		path.pop_back();
	}
	if(valid(i,j+1)){
		path.push_back(Mat[i][j+1]);
		bk(i,j+1);
		path.pop_back();
	}
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
	path.push_back(Mat[0][0]);
	bk(0,0);
	for(auto it : st){
		for(auto it2 : it){
			cout << it2 << " ";
		}
		cout << endl;
	}


}