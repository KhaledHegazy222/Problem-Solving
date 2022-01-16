#include <bits/stdc++.h>
#define fast cin.tie(0),ios::sync_with_stdio(0),cout.tie();
#define all(a) a.begin(),a.end()

typedef long long ll;
typedef unsigned long long ull;

using namespace std;


const ll N = 1e3;

ll NCR[N][N];


void init(){
	for(ll i = 0;i < N;i++){
		NCR[i][0] = 1;
	}
	for(ll i = 1;i < N;i++){
		for(ll j = 1;j <= i;j++){
			NCR[i][j] = NCR[i - 1][j] + NCR[i-1][j - 1]; 
		}
	}
}


signed main(void){

    #ifdef Khaled
        freopen("in.txt","r",stdin);
        //freopen("out.txt","w",stdout);
    #endif
    #ifndef Khaled
        #define endl '\n'
        fast;
    #endif

	// init();
	// for(ll i = 0;i < 128;i++){
	// 	ll even = 0,odd = 0;

	// 	for(ll j = 0;j <=i;j++){
	// 		even += !(NCR[i][j] % 2);
	// 		odd += NCR[i][j] % 2;
	// 		// cout << left << setw(15) << NCR[i][j];
	// 	}
	// 	cout << even << " " << odd;
	// 	cout << endl;
	// }

	ll t;
	cin >> t;
	while(t--){
		ll n;
		cin >> n;

		// if(n < 2){
		// 	cout << n + 1<< endl;
		// 	continue;
		// }
		ll base = 1;
		ll x = n;
		while(n){
			if(n % 4 == 1 || n % 4 == 2)
				base <<= 1;
			if(n % 4 == 3)
				base <<= 2;
			
			n /= 4;
		}
		n = x;
		cout << (n + 1 - base) << " " <<  base << endl;
	}
}


