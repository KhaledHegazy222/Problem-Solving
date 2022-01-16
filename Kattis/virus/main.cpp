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

	string org;
	string infected;
	cin >> org >> infected;
	int begin = 0;
	for(int i = 0;i<org.size();i++){
		if(org[i] == infected[i]){
			begin++;
			org[i] = infected[i] = 'z';
		}
		else break;
	}
	int back = 0;
	for(int i = org.size()-1,j = infected.size()-1;i >= 0 && j >= 0;i--,j--){
		if(org[i] == infected[j]) back++;
		else break;
	}
	int ttl = begin + back;
	if(org == infected) cout << 0 << endl;
	else cout << infected.size() - ttl << endl;

}	