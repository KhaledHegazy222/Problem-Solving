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
    ll cs = 1;
    ll t;
    cin >> t;
    while(t--){
        ll a,b,c;
        cin >> a >> b >> c;


        cout << "Case " << cs++ << ": ";
        if(c % __gcd(a,b))
            cout << "No\n";
        else
            cout << "Yes\n";

    }

}


