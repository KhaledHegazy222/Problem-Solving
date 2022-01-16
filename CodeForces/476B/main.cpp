
#include <bits/stdc++.h>

#define all(a) a.begin(),a.end()
#define fast cin.tie(0),ios::sync_with_stdio(0),cout.tie(0)
#define ll long long 

using namespace std;
string org;
string s;
int res;
int x;
string current;


int eval(){
	string a = org;
	string b = current;
	sort(all(a));
	sort(all(b));
	return a == b;
}


void solve(int idx){
	if(idx == s.size()){
		res += eval();
		return;
	}

	if(s[idx] == '?'){
		current.push_back('+');
		solve(idx + 1);
		current.pop_back();
		current.push_back('-');
		solve(idx + 1);
		current.pop_back();
	}
	else{
		current.push_back(s[idx]);
		solve(idx + 1);
		current.pop_back();
	}
}




int main(void){	
	fast;
	#ifdef Khaled
		freopen("in.txt","r",stdin);
		//freopen("out.txt","w",stdout);
	#endif
	cin >> org >> s;
	for(auto it : s){
		x += (it == '?');
	}
	solve(0);
	cout << fixed << setprecision(11) << ((double) res ) / (1 << x) << endl;
}