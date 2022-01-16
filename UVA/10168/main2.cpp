#include <bits/stdc++.h>
#define fast cin.tie(0),ios::sync_with_stdio(0),cout.tie();
#define all(a) a.begin(),a.end()

typedef long long ll;
typedef unsigned long long ull;

using namespace std;
const ll N = 1e7 + 5;
vector<ll>isPrime(N,1);
vector<ll>primes;

void sieve(){
    isPrime[0] = isPrime[1] = 0;
    for(ll i = 2;i * i < N;i++)
        if(isPrime[i])
            for(ll j = 2 * i;j < N;j += i)
                isPrime[j] = 0;


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

    ll n;
    while(cin >> n){
        if(n < 8){
            cout << "Impossible.\n";
            continue;
        }
        vector<ll>v;
        if(n % 2){
            v.push_back(2);
            v.push_back(3);
            n -= 5;

        }   
        else{
            v.push_back(2);
            v.push_back(2);
            n -= 4;
        }


        for(ll i = 0;i<primes.size() && primes[i] < n;i++){
            if(isPrime[n - primes[i]]){
                v.push_back(primes[i]),v.push_back(n - primes[i]);
                break;
            }
        }
        for(auto elem : v)
            cout << elem << " ";
        cout << endl;
        
        
    }
}


