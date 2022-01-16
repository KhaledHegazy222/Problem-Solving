#include <bits/stdc++.h>

#define all(a) a.begin(),a.end()
#define fast cin.tie(0),ios::sync_with_stdio(0),cout.tie(0)
#define ll long long 
#define MOD 1000000007

using namespace std;
 

int ii[4] = {0,1,0,-1};
int jj[4] = {1,0,-1,0};
const int N = 1e3 + 3;
int Mat[N][N];
int n,done;
vector<int> res;

int valid(int i,int j){
	return i >= 0 && i < n && j >= 0 && j < n;
}

void rec(int mv,int i,int j){
	res.push_back(Mat[i][j]);
	done++;
	Mat[i][j] = -1;
	int ni = i + ii[mv];
	int nj = j + jj[mv];
	if(valid(ni,nj) && Mat[ni][nj] != -1)
		rec(mv,ni,nj);
	else if(done == n * n)
		return;
	else{
		mv = (mv + 1) % 4;
		ni = i + ii[mv];
		nj = j + jj[mv];
		rec(mv,ni,nj);
	}
		
}



int main(void){	
	fast;
	#ifdef Khaled
		freopen("in.txt","r",stdin);
		//freopen("out.txt","w",stdout);
	#endif	

	cin >> n;
	for(int i = 0;i<n;i++){
		for(int j = 0;j<n;j++){
			cin >> Mat[i][j];
		}
	}

	rec(0,0,0);
	for(int i = 0;i<done;i++){
		cout << res[i] << " \n"[(i + 1)% n == 0];
	}




}