
#include <bits/stdc++.h>

#define all(a) a.begin(),a.end()
#define fast cin.tie(0),ios::sync_with_stdio(0),cout.tie(0)
#define ll long long 

using namespace std;

string s1,s2;



int lcs(int i = 0,int j = 0){
	if(i == s1.size() || j == s2.size())
		return 0;
	
	if(s1[i] == s2[j]){
		return 1 + lcs(i + 1,j + 1);
	}
	else{
		return max(lcs(i + 1,j),lcs(i,j+1));
	}
}	


int main(void){	
	fast;
	#ifdef Khaled
		freopen("in.txt","r",stdin);
		//freopen("out.txt","w",stdout);
	#endif	

	cin >> s1 >> s2;
	cout << lcs() << endl;





}