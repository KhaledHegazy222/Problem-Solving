#include <bits/stdc++.h>
#define fast cin.tie(0),ios::sync_with_stdio(0),cout.tie();
#define all(a) a.begin(),a.end()

typedef long long ll;
typedef unsigned long long ull;

using namespace std;

signed main(void){

    #ifdef Khaled
        freopen("in.txt","r",stdin);
        //freopen("out.txt","w",stdout);
    #endif
    #ifndef Khaled
        #define endl '\n'
        fast;
    #endif
    
    ll n;
    cin >> n;
    ll i = 0;
    ll res = 1e18;
    while(n >= (1ll << i)){
        ll a = n / (1ll << i);
        ll c = n - a * (1ll << i);
        res = min(res,a + i + c);
        i++;
    }
    cout << res << endl;

}


