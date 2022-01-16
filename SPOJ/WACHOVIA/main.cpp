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


int n;
int k,m;

vector<pair<int,int> >bags(51);

int mem[52][1002];


int dp(int index,int reminder){
	if(reminder < 0 ) return -1e7;
	if(index == m) return 0;
	int &ret = mem[index][reminder];
	if(ret != -1){
		return ret;
	}
	int ch1 = dp(index+1,reminder);
	int ch2 = bags[index].second + dp(index+1,reminder-bags[index].first);

	return ret = max(ch1,ch2);
}




int main(void){
	fast;
	#ifdef Khaled
		freopen("out.txt","w",stdout);
		freopen("in.txt","r",stdin);
	#endif
	#ifndef Khaled
		//freopen(".in","r",stdin);
	#endif

	cin >> n;
	while(n--){
		memset(mem,-1,sizeof(mem));
		cin >> k >> m;
		for(int i = 0;i<m;i++){
			cin >> bags[i].first >> bags[i].second;
		}

		cout << "Hey stupid robber, you can get " << dp(0,k) << ".\n";
	}




}	


