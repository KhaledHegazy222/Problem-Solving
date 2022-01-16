
#include <bits/stdc++.h>

#define all(a) a.begin(),a.end()
#define fast cin.tie(0),ios::sync_with_stdio(0),cout.tie(0)
#define ll long long 

using namespace std;




string s,current;
vector<string>v;

bool palindrome(string &s){
	for(int i = 0;i<s.size() / 2;i++){
		if(s[i] != s[s.size() - i - 1])
			return 0;
	}
	return 1;
}



void solve(int pos){
		
	if(pos == s.size()){
		if(current.size() && palindrome(current))
			v.push_back(current);
		return;
	}


	solve(pos + 1);
	current.push_back(s[pos]);
	solve(pos + 1);
	current.pop_back();
}



int main(void){	
	fast;
	#ifdef Khaled
		freopen("in.txt","r",stdin);
		//freopen("out.txt","w",stdout);
	#endif
	cin >> s;
	solve(0);
	sort(all(v));
	cout << v.back() << endl;

}