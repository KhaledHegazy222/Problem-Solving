#include <bits/stdc++.h>

#define all(a) a.begin(),a.end()
#define fast cin.tie(0),ios::sync_with_stdio(0),cout.tie(0)
#define ll long long 
#define MOD 1000000007

using namespace std;
const int N = 10;
int Mat[10][10];


int n,m;


int valid(int i,int j){
	return i >= 0 && i < n && j >= 0 && j < m;
}

int bk(int i,int j){
	if(i+1 == n && j+1 == m)
		return Mat[i][j];
	int ch1 = -1e9;
	int ch2 = -1e9;
	if(valid(i,j+1))
		ch1 = bk(i,j+1);

	if(valid(i+1,j))
		ch2 = bk(i+1,j);

	return Mat[i][j] + max(ch1,ch2);
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

	cout << bk(0,0) << endl;



}