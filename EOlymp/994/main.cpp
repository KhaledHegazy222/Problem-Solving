
#include <bits/stdc++.h>

#define all(a) a.begin(),a.end()
#define fast cin.tie(0),ios::sync_with_stdio(0),cout.tie(0)
#define ll long long 
#define ull unsigned long long 

using namespace std;
int main(void){	
	//fast;
	#ifdef Khaled
		freopen("in.txt","r",stdin);
		//freopen("out.txt","w",stdout);
	#endif
	
	int n;
	cin >> n;
	int Mat[n][n];
	for(int i = 0;i<n;i++){
		for(int j = 0;j<n;j++){
			cin >> Mat[i][j];
		}
	}
	int colors[n];
	for(int i = 0;i<n;i++){
		cin >> colors[i];
	}
	int res = 0;
	for(int i = 0;i<n;i++){
		for(int j = 0;j<n;j++){
			if(Mat[i][j] && colors[i] != colors[j])
				res++;
		}
	}
	cout << res / 2<< endl;



}	