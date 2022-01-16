#include <bits/stdc++.h>
#define fast cin.tie(0),ios::sync_with_stdio(0),cout.tie();
#define all(a) a.begin(),a.end()

typedef long long ll;
typedef unsigned long long ull;

using namespace std;


map<ll,ll> factorize(ll n){
    map<ll,ll>ret;

    for(ll i = 2;i * i <= n;i++){
        while(n % i == 0){
            ret[i]++;
            n /= i;
        }
    }
    ret[n]++;
    return ret;
    
}



ll count(ll fact,ll p){
    ll cnt = 0;
    for(ll i = p;i <= fact;i *= p){
        cnt += fact / i;
    }
    return cnt;
}



ll divisable(ll fact,map<ll,ll>& primes){
    ll valid = 1;
    ll again = 1;
    while(again){
        again = 0;
        for(auto elem : primes){
            if(elem.first == 1)
                continue;

            if(count(fact,elem.first) < elem.second)
                valid = 0;
            else{
                if(primes.find(elem.first) != primes.end()){
                    primes.erase(elem.first);
                    again = 1;
                    break;
                }
            }
        }
    }
    
    return valid;

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
    cin >> a >> b;

    ll res = 0;
    auto A = factorize(a);
    auto B = factorize(b);
    for(ll i = 0;i < b;i++){
        res += divisable(i,A) && !divisable(i,B);
    }


    cout << res << endl;



}


