/*
	Created By : Khaled Hegazy
*/


#include <bits/stdc++.h>
#define all(x) x.begin(),x.end()
#define fast cin.tie(0),ios::sync_with_stdio(0),cout.tie(0)

using namespace std;

typedef unsigned long long ull;
typedef long long ll;


vector<int>inv;


int merge(int s1,int e1,int s2 ,int e2){
	int ret = 0;

	vector<int>v;
	int i = s1;
	int j = s2;
	while(i <= e1 && j <= e2){
		if(inv[i] < inv[j]){
			v.push_back(inv[i++]);
		}	
		else{
			ret += e1 - i + 1;
			v.push_back(inv[j++]);
		}
	}

	while(i <= e1){
		v.push_back(inv[i++]);
	}
	while(j <= e2){
			ret += e1 - i + 1;
			v.push_back(inv[j++]);
	}
	for(int k = 0;k < v.size();k++){
		inv[s1++] = v[k];
	}
	return ret;
	
}


int count_inv(int st,int en){
	if(st == en) return 0;
	int mid = (st + en) / 2;
	int cnt = 0;
	cnt = count_inv(st,mid);
	cnt += count_inv(mid+1,en);
	return cnt + merge(st,mid,mid+1,en);

}






int main(void){
	fast;
	#ifdef Khaled
		freopen("out.txt","w",stdout);
		freopen("in.txt","r",stdin);
	#endif
	#ifndef Khaled
		//freopen(".in","r",stdin);
	#endif

	int t;
	cin >> t;
	while(t--){
		int n;
		cin >> n;
		vector<string>v;
		for(int i = 0;i<n;i++){
			string s;
			cin >> s;
			v.push_back(s);
		}
		
		map<string,int>mp;
		for(int i = 0 ;i<n;i++){
			string s;
			cin >> s;
			mp[s] = i;
		}
		inv.resize(n);
		for(int i = 0;i<n;i++){
			inv[i] = mp[v[i]];
		}

		cout << count_inv(0,n-1) << endl;
		
	}





}
