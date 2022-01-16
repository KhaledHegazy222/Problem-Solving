
#include <bits/stdc++.h>

#define all(a) a.begin(),a.end()
#define fast cin.tie(0),ios::sync_with_stdio(0),cout.tie(0)
#define ll long long 

using namespace std;


int n,l,r,x;
int res = 0;
vector<int>vals;
vector<int>choosen;

void sol(int idx = -1){
	if(choosen.size() >= 2){
		int sum = 0;
		int mn = INT_MAX;
		int mx = INT_MIN;
		for(auto it : choosen){
			sum += it;
			mx = max(mx,it);
			mn = min(mn,it);
		}
		if(mx - mn >= x && sum >= l && sum <= r)
			res++;
	}

	for(int i = idx + 1;i<n;i++){
		choosen.push_back(vals[i]);
		sol(i);
		choosen.pop_back();
	}

}


int main(void){	
	fast;
	#ifdef Khaled
		freopen("in.txt","r",stdin);
		//freopen("out.txt","w",stdout);
	#endif	

	cin >> n >> l >> r >> x;
	vals.resize(n);


	for(int i = 0;i<n;i++){
		cin >> vals[i];
	}

	sol();
	cout << res << endl;






}