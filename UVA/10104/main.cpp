#include <bits/stdc++.h>
#define fast cin.tie(0),ios::sync_with_stdio(0),cout.tie();
#define all(a) a.begin(),a.end()

typedef long long ll;
typedef unsigned long long ull;

using namespace std;



ll extended_eculidean(ll a,ll b,ll &x,ll &y){
    if(!b){
        x = 1;
        y = 0;
        return a;
    }
    ll x1,y1;
    ll g = extended_eculidean(b,a % b,x1,y1);
    x = y1;
    y = x1 - y1 * (a / b);

    return g;


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

    ll a,b;
    while(cin >> a >> b){
        ll x,y;
        ll g = extended_eculidean(a,b,x,y);

        cout << x << " " << y << " " << g << endl;
    }

}


