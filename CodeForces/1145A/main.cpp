#include <bits/stdc++.h>

#define all(a) a.begin(),a.end()
#define fast cin.tie(0),ios::sync_with_stdio(0),cout.tie(0)
#define ll long long 
#define MOD 1000000007

using namespace std;

int is_sorted(vector<int> & v){
	for(int i = 1;i<v.size();i++){
		if(v[i] < v[i - 1])
			return 0;
	}
	return 1;
}

int bk(vector<int>v){
	if(is_sorted(v))
		return v.size();
	int mid = v.size() / 2;
	vector<int>l,r;
	for(int i = 0;i<mid;i++){
		l.push_back(v[i]);
	}
	for(int i = mid;i<v.size();i++){
		r.push_back(v[i]);
	}
	
	return max(bk(l),bk(r));
}

int main(void){	
	fast;
	#ifdef Khaled
		freopen("in.txt","r",stdin);
		//freopen("out.txt","w",stdout);
	#endif	
		
	int n;
	cin >> n;
	
	vector<int>v(n);
	for(int i =0;i<n;i++){
		cin >> v[i];
	}

	cout << bk(v);

}