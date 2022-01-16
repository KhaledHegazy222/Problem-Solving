
#include <bits/stdc++.h>

#define all(a) a.begin(),a.end()
#define fast cin.tie(0),ios::sync_with_stdio(0),cout.tie(0)
#define ll long long 

using namespace std;

int k;
vector<int>scores(11);
int res;
map<int,int>frq;


void solve(int current,int taken){
	if(taken == k){
		frq[res]++;
		return;
	}

	for(int i = current;i<11;i++){
		res += scores[i];
		solve(i + 1,taken + 1);
		res -= scores[i];
	}
}




int main(void){	
	fast;
	#ifdef Khaled
		freopen("in.txt","r",stdin);
		//freopen("out.txt","w",stdout);
	#endif
	int t;
	cin >> t;
	while(t--){
		for(int i = 0;i<11;i++){
			cin >> scores[i];
		}
		cin >> k;
		solve(0,0);
		cout << frq.rbegin()->second << endl;
		frq.clear();
	}
}