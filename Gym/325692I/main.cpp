
#include <bits/stdc++.h>

#define all(a) a.begin(),a.end()
#define fast cin.tie(0),ios::sync_with_stdio(0),cout.tie(0)
#define ll long long 

using namespace std;


int n;
vector<int>v;


int lis(int pos = 0,int last = -1){
	if(pos == n)
		return 0;
	
	int ch1 = lis(pos + 1,last);
	int ch2 = 0;
	if(last < v[pos])
		ch2 = 1 + lis(pos + 1,v[pos]);
	return max(ch1,ch2);
}


int main(void){	
	fast;
	#ifdef Khaled
		freopen("in.txt","r",stdin);
		//freopen("out.txt","w",stdout);
	#endif	
	cin >> n;
	v.resize(n);

	for(int i = 0;i<n;i++){
		cin >> v[i];
	}
	cout << lis() << endl;
}