
#include <bits/stdc++.h>

#define all(a) a.begin(),a.end()
#define fast cin.tie(0),ios::sync_with_stdio(0),cout.tie(0)
#define ll long long 

using namespace std;

const int N = 10;
int n;
int rows[N],cols[N],diag[(N - 1) * 2 + 1],diagInv[(N - 1) * 2 + 1];
vector<pair<int,int>>qs;
int res = 0;
int exist = 0;
void sol(int pos){
	if(qs.size() == n){
		char Mat[n][n];
		for(int i =0;i<n;i++){
			for(int j = 0;j<n;j++){
				Mat[i][j] = '.';
			}
		}
		for(auto it : qs){
			Mat[it.first][it.second] = 'Q';
		}
		if(exist){
			cout << endl;
		}
		exist = 1;
		for(int i =0;i<n;i++){
			for(int j = 0;j<n;j++){
				cout << Mat[i][j];
			}
			cout << endl;
		}
		return;
	}

	for(int x = pos +1;x < n * n;x++){
		int i = x / n;
		int j = x % n;

		int d1 = j - i + n - 1;
		int d2 = i + j;
		if(!rows[i] && !cols[j] && !diag[d1] && !diagInv[d2]){
			rows[i] = cols[j] = diag[d1] = diagInv[d2]= 1;
			qs.push_back({i,j});
			sol(x);
			rows[i] = cols[j] = diag[d1] = diagInv[d2]= 0;
			qs.pop_back();
		}
	}
	
	




}



int main(void){	
	fast;
	#ifdef Khaled
		freopen("in.txt","r",stdin);
		//freopen("out.txt","w",stdout);
	#endif	
	cin >> n;
	sol(-1);
}