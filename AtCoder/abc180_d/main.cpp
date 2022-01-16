/*
	Created By : Khaled Hegazy
*/


#include <bits/stdc++.h>
#define all(x) x.begin(),x.end()
#define fast cin.tie(0),ios::sync_with_stdio(0),cout.tie(0)
#define PI (acos(-1))


using namespace std;

typedef unsigned long long ull;
typedef long long ll;






int main(void){
	fast;
	#ifdef Khaled
		freopen("out.txt","w",stdout);
		freopen("in.txt","r",stdin);
	#endif
	#ifndef Khaled
		//freopen(".in","r",stdin);
	#endif	

	ll str,y,a,b;
	cin >> str >> y >> a >> b;
	ll inc = 0;
	loop:
	int valid = 1;
	int digits = 2 + log10(str) + log10(a);
	if(digits > 18)
		valid = 0;
	if(str + b  >= y && (valid || str * a  >= y)){
		cout << inc << endl;
		return 0;
	}
	if(valid &&  a * str < str + b){
		inc++;
		str *= a;
		goto loop;
	}
	else{
		inc += max(0ll,(y - str - 1))/b;
		cout << inc << endl;
		return 0;
	}
}	


