#include <bits/stdc++.h>
#define fast cin.tie(0),ios::sync_with_stdio(0),cout.tie();
#define all(a) a.begin(),a.end()

typedef long long ll;
typedef unsigned long long ull;

using namespace std;

ll MOD = 1e12;

ll safeMul(ll b,ll p){

    ll ret = 0;
    while(p){
        if(p & 1){
            ret += b;
            ret %= MOD;
        }

        b += b;
        b %= MOD;
        p >>= 1;
    }
    return ret;

}


ll power(ll b,ll p){

    ll ret = 1;
    while(p){
        if(p & 1){
            ret = safeMul(ret,b);
        }

        b = safeMul(b,b);
        p >>= 1;
    }
    return ret;

}


map<ll,ll>factorize(ll n){
    map<ll,ll>ret;

    for(ll i = 2;i * i <= n;i++)
        while(n % i == 0){
            ret[i]++;
            n /= i;
        }
    if(n != 1)
        ret[n]++;
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

    // ll n;
    // cin >> n;
    // ll A = 1,B = 1;
    // while(n--){
    //     ll x;
    //     cin >> x;
    //     A = safeMul(A,x);
    //     // A *= x;
    // }
    // cin >> n;
    // while(n--){
    //     ll x;
    //     cin >> x;
    //     B = safeMul(B,x);
    //     // B *= x;
    // }

    // ll res = __gcd(A,B);

    // cout << res << endl;
    

    map<ll,ll>A;
    ll n;
    cin >> n;
    while(n--){
        ll x;
        cin >> x;
        auto mp = factorize(x);
        for(auto elem : mp){
            A[elem.first] += elem.second;
        }
    }
    map<ll,ll>B;
    cin >> n;
    while(n--){
        ll x;
        cin >> x;
        auto mp = factorize(x);
        for(auto elem : mp){
            B[elem.first] += elem.second;
        }
    }
    map<ll,ll>res;
    for(auto elem : A){
        res[elem.first] = min(elem.second,B[elem.first]);   
    }
    for(auto elem : B){
        res[elem.first] = min(elem.second,A[elem.first]);
    }

    ll ans = 1;
    for(auto elem : res){
        ans = safeMul(ans,power(elem.first,elem.second));
    }
    ll flag = 0;
    if(ans >= (ll)1e9)
        flag = 1;
    ans %= (ll)1e9;
    if(!ans){
        if(flag){
            cout << "000000000\n";
            return 0;
        }
        else
            return cout << 0 << endl,0;
    }
    if(flag){
        for(ll i = 0;i<9 - (1 + log10(ans));i++){
            cout << '0';
        }
    }
        
    cout << ans << endl;



}


