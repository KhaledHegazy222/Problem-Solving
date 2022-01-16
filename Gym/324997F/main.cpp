#include <bits/stdc++.h>

#define all(a) a.begin(),a.end()
#define fast cin.tie(0),ios::sync_with_stdio(0),cout.tie(0)
#define ll long long 
#define MOD 1000000007

using namespace std;




int main(void){	
	fast;
	#ifdef Khaled
		freopen("in.txt","r",stdin);
		//freopen("out.txt","w",stdout);
	#endif	

	int ra,ca;
	cin >> ra >> ca;
	int A[ra][ca];
	for(int i = 0;i<ra;i++){
		for(int j = 0;j<ca;j++){
			cin >> A[i][j];
		}
	}
	int rb,cb;
	cin >> rb >> cb;
	int B[rb][cb];
	for(int i = 0;i<rb;i++){
		for(int j = 0;j<cb;j++){
			cin >> B[i][j];
		}
	}	
	int C[ra][cb];
	memset(C,0,sizeof(C));
	for(int i = 0;i<ra;i++){
		for(int j = 0;j<cb;j++){
			for(int k = 0;k<rb;k++){
				C[i][j] += A[i][k] * B[k][j];
			}
		}
	}
	for(int i = 0;i<ra;i++){
		for(int j = 0;j<cb;j++){
			cout << C[i][j] << " ";
		}
		cout << endl;
	}




}