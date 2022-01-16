
#include <bits/stdc++.h>

#define all(a) a.begin(),a.end()
#define fast cin.tie(0),ios::sync_with_stdio(0),cout.tie(0)
#define ll long long 

using namespace std;

int main(void){

	#ifdef Khaled
		freopen("in.txt","r",stdin);
		//freopen("out.txt","w",stdout);
	#endif
    fast;

    int t;
    cin >> t;
    while(t--){
        ll n,x,t;
        cin >> n >> x >> t;




        ll fj = 2 * n * t;
        ll res = 0;
        if(fj >= 2 * t + x){ // second man ended
            res = 2 * fj;
        }
        else if(fj >= t + x){   // first man ended
            res = fj + (2*t + x - fj) + fj;
        }
        else if(fj + t >= x + t){ // i will arrive after first end
            res = fj * 2 + t;
        }
        else{ // first man didn't end yet
            res = t + x + fj;

        }
        cout << res << endl;
    }








}