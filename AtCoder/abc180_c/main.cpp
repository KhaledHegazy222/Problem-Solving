#include <bits/stdc++.h>
#define fast cin.tie(0),ios::sync_with_stdio(0),cout.tie();
#define all(a) a.begin(),a.end()

typedef long long ll;
typedef unsigned long long ull;

using namespace std;


set<ll> div(ll n){
    set<ll>ret;
    for(ll i = 1;i * i <= n;i++){
        if(n % i == 0){
            ret.insert(i);
            ret.insert(n / i);
        }
    }
    return ret;
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
    ll n;
    cin >> n;
    auto st = div(n);
    for(auto elem : st)
        cout << elem << endl;

}


