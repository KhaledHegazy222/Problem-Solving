
#include <bits/stdc++.h>

#define all(a) a.begin(),a.end()
#define fast cin.tie(0),ios::sync_with_stdio(0),cout.tie(0)
#define ll long long 

using namespace std;

vector<vector<string>>res;
vector<string>combination;
vector<string>vals;
int n,r;

void ncr(int i = 0,int last_val = -1){
	if(i == r){
		res.push_back(combination);
		return;
	}
	for(int j = last_val + 1;j<n;j++){
		combination.push_back(vals[j]);
		ncr(i + 1,j);
		combination.pop_back();
	}


}



int main(void){	
	fast;
	#ifdef Khaled
		freopen("in.txt","r",stdin);
		//freopen("out.txt","w",stdout);
	#endif	
	cin >> n >> r;

	for(int i = 0;i<n;i++){
		string x;
		cin >> x;
		vals.push_back(x);
	}
	sort(all(vals));
	ncr();
	for(int i = 0;i<res.size();i++){
		for(int j = 0;j<r;j++){
			cout << res[i][j] << " ";
		}
		cout << endl;
	}

}