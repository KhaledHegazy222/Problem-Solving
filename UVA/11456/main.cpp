#include <bits/stdc++.h>
#define fast cin.tie(0),ios::sync_with_stdio(0),cout.tie();
#define all(a) a.begin(),a.end()

typedef long long ll;
typedef unsigned long long ull;

using namespace std;


const int N = 2e3 + 5;

int A[N],n;


int dpLIS[N][N],dpLDS[N][N];



int LIS(int idx,int last){
	if(idx == n)
		return 0;
	int &ret = dpLIS[idx][last];
	if(~ret)
		return ret;
	ret = LIS(idx + 1,last);
	if(A[idx] > A[last])
		ret = max(ret,1 + LIS(idx + 1,idx));
	return ret;
}


int LDS(int idx,int last){
	if(idx == n)
		return 0;
	
	int &ret = dpLDS[idx][last];
	if(~ret)
		return ret;
	ret = LDS(idx + 1,last);
	if(A[idx] < A[last])
		ret = max(ret,1 + LDS(idx + 1,idx));
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

	int t;
	cin >> t;
	while(t--){
		cin >> n;
		for(int i = 0;i < n;i++)
			cin >> A[i];


		memset(dpLIS,-1,sizeof dpLDS);
		memset(dpLDS,-1,sizeof dpLIS);
		int res = 0;
		for(int i = 0;i < n;i++){
			res = max(res,1 + LIS(i,i) + LDS(i,i));
		}
		cout << res << endl;
	}



}


