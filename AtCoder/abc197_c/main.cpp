
#include <bits/stdc++.h>

#define all(a) a.begin(),a.end()
#define fast cin.tie(0),ios::sync_with_stdio(0),cout.tie(0)
#define ll long long 

using namespace std;

vector<vector<int>>seg;

vector<int>v;
int n;

int res = INT_MAX;


int eval(){
	vector<int>ret;
	for(auto it : seg){
		int x = 0;
		for(auto it2 : it){
			x |= it2;
		}
		ret.push_back(x);
	}
	int res = 0;
	for(auto it : ret){
		res ^= it;
	}
	return res;
}


int sol(int idx){
	if(idx == n){
		return eval();
	}


	seg.back().push_back(v[idx]);
	int ch1 = sol(idx + 1);

	seg.back().pop_back();
	seg.push_back({v[idx]});
	int ch2 = sol(idx + 1);

	seg.pop_back();
	return min(ch1,ch2);
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

	seg.push_back({v[0]});
	cout << sol(1) << endl;




}