// #include <bits/stdc++.h>
// #define fast cin.tie(0),ios::sync_with_stdio(0),cout.tie();
// #define all(a) a.begin(),a.end()

// typedef long long ll;
// typedef unsigned long long ull;

// using namespace std;

// ll range(ll l,ll x){
//     return max(0,l / x);
// }
// ll range2(ll l,ll r,ll x){
//     return range(r,x) - range(l - 1,x);
// }



// signed main(void){

//     #ifdef Khaled
//         freopen("in.txt","r",stdin);
//         //freopen("out.txt","w",stdout);
//     #endif
//     #ifndef Khaled
//         #define endl '\n'
//         fast;
//     #endif

//     ll t;
//     cin >> t;
//     while(t--){
//         ll l,r,x;
//         cin >> l >> r >> x;
//         cout << range2(l,r,x) << endl;
//     }
    

// }
#include <bits/stdc++.h>
#define fast cin.tie(0),ios::sync_with_stdio(0),cout.tie();
#define all(a) a.begin(),a.end()

typedef long long ll;
typedef unsigned long long ull;

using namespace std;
const ll MOD = 1e9 + 7;

ll power(ll b,ll p){
    ll ret = 1;
    while(p){
        if(p & 1)
            ret = (1ll * ret * b) % MOD;
        b = (1ll * b * b) % MOD;
        p >>= 1;
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
    
    ll t;
    cin >> t;
    while(t--){
        ll n;
        cin >> n;
        cout << (power(2,n) - 1 + MOD) % MOD << endl;
    }




}





