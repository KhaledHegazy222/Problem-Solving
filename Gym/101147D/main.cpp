#include <bits/stdc++.h>
#define fast cin.tie(0),ios::sync_with_stdio(0),cout.tie();
#define all(a) a.begin(),a.end()

typedef long long ll;
typedef unsigned long long ull;

using namespace std;


ll fact(ll n){
    ll ret = 1;
    while(n--){
        ret *= n + 1;
    }

    return ret;
}


ll ncr(ll n,ll r){
    return fact(n) / (fact(r) * fact(n - r));
}





signed main(void){

    #ifdef Khaled
        freopen("in.txt","r",stdin);
        //freopen("out.txt","w",stdout);
    #endif
    #ifndef Khaled
        freopen("popcorn.in","r",stdin);
        #define endl '\n'
        fast;
    #endif

    ll t;
    cin >> t;
    while(t--){
        ll n,r;
        cin >> n >> r;
        cout << ncr(n,r) << endl;
    }
    

}


