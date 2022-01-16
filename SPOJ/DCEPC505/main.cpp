#include <bits/stdc++.h>
#define fast cin.tie(0),ios::sync_with_stdio(0),cout.tie();
#define all(a) a.begin(),a.end()

typedef long long ll;
typedef unsigned long long ull;

using namespace std;


const ll N = 2e7+ 5;



vector<ll>isPrime(N,1);
vector<ll>primes;

void sieve(){
    isPrime[0] = isPrime[1] = 0;
    for(ll i = 2;i * i <= N;i++){
        if(isPrime[i])
            for(ll j = 2 * i;j < N;j += i)
                isPrime[j] = 0;
    }
    for(ll i = 0;i<N;i++)  
        if(isPrime[i])
            primes.push_back(i);
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
    

    sieve();
    vector<ll>res;
    for(ll i = 0;i < primes.size();i++)
        for(ll j = i + 1;j < primes.size() && primes[i] * primes[j] < N;j++)
            res.push_back(primes[i] * primes[j]);
        
    sort(all(res));

    ll t;
    cin >> t;
    while(t--){
        ll k;
        cin >> k;
        cout << res[--k] << endl;

    }
}


