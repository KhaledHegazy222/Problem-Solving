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

ll n,l,r;
ll a[20];

ll solve(ll idx,ll sum){
    if(idx == n)
        return sum >= l && sum <= r;
    

    return solve(idx + 1,sum + a[idx]) + solve(idx + 1,sum);
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
    cin >> n >> l >> r;
    for(ll i = 0; i < n;i++)
        cin >> a[i];
    cout << solve(0,0) << endl;

}





