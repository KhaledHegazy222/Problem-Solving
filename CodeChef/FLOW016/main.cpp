#include <bits/stdc++.h>
#define fast cin.tie(0),ios::sync_with_stdio(0),cout.tie();
#define all(a) a.begin(),a.end()

typedef long long ll;
typedef unsigned long long ull;

using namespace std;

ll lcm(ll a,ll b){
    return a / __gcd(a,b) * b;
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
    
    ll t;
    cin >> t;
    while(t--){
        ll a,b;
        cin >> a >> b;
        cout << __gcd(a,b) << " " << lcm(a,b) << endl;
    }
}


