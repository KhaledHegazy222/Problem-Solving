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
    vector<ll>v(n);
    ll man = 0;
    ll cheb = 0;
    ll euc = 0;
    for(ll i = 0;i<n;i++){
        cin >> v[i];
        man += abs(v[i]);
        cheb = max(cheb,abs(v[i]));
        euc += abs(v[i]) * abs(v[i]);
    }    
    cout << man << endl;
    cout << fixed << setprecision(11) << sqrtl(euc) << endl;
    cout << cheb << endl;


}


