#include <bits/stdc++.h>

#define all(a) a.begin(),a.end()
#define fast cin.tie(0),ios::sync_with_stdio(0),cout.tie(0)
#define ll long long 
#define MOD 1000000007

using namespace std;

int valid(string x){
	stack<char>st;
	for(auto it : x){
		if(it == '(')
			st.push('(');
		else if(!st.empty())
			st.pop();
		else
			return 0;
	}
	return 1;

}



int main(void){	
	fast;
	#ifdef Khaled
		freopen("in.txt","r",stdin);
		//freopen("out.txt","w",stdout);
	#endif	

	int n;
	cin >> n;
	string res;
	for(int i = 0;i<n;i++){
		res.push_back('(');
	}
	for(int i = 0;i<n;i++){
		res.push_back(')');
	}

	do{	

		if(valid(res)){
			cout << res << endl;
		}

	}while(next_permutation(all(res)));


	

}