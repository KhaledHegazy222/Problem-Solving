
#include <bits/stdc++.h>

#define all(a) a.begin(),a.end()
#define fast cin.tie(0),ios::sync_with_stdio(0),cout.tie(0)
#define ll long long 

using namespace std;

const int N = 1e6 + 3;


int solve(ll c){
    for(ll i = 2;i < N;i++){
        if(c % i == 0){
            int cnt = 0;
            while(c % i == 0){
            	c /= i;
            	cnt++;
            }
            if(cnt >= 2)
            	return 1;
        }
    }
    ll sq = sqrt(c);
    if(c != 1 && sq * sq == c)
    	return 1;
    return 0;
}


int main(void){

	#ifdef Khaled
		freopen("in.txt","r",stdin);
		//freopen("out.txt","w",stdout);
	#endif
    fast;

    ll t;

    cin >> t;
    while(t--){
        ll c;
        cin >> c;
        cout << (solve(c) ? "yes\n" : "no\n");
    }





}