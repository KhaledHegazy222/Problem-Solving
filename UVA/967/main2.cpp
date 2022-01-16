#include <bits/stdc++.h>
#define fast cin.tie(0),ios::sync_with_stdio(0),cout.tie();
#define all(a) a.begin(),a.end()

typedef long long ll;
typedef unsigned long long ull;

using namespace std;

const int N = 1e7 + 5;

vector<int>isPrime(N,1);
vector<int>primes;
int com[N];

void sieve(){
    isPrime[0] = isPrime[1] = 0;
    for(int i = 2;i * i < N;i++)
        if(isPrime[i])
            for(int j = 2 * i;j < N;j += i)
                isPrime[j] = 0;
    for(int i = 0;i<N;i++) 
        if(isPrime[i])
            primes.push_back(i);
}

int circularPrime(int n){
    string s = to_string(n);
    for(int i = 0;i<s.size();i++){
        if(!isPrime[stoi(s)])
            return 0;
        s.push_back(s.front());
        s.erase(s.begin());
    }
    return 1;
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



    for(int i = 100;i<N;i++)
        com[i] = com[i - 1] + (isPrime[i] && circularPrime(i));

    int l,r;
    while(cin >> l){
        if(l < 0)
            return 0;
        cin >> r;
        // int idx = lower_bound(all(primes),l) - primes.begin();
        int res = com[r] - com[l - 1];
        // for(int i = idx;primes[i] <= r;i++){
        //     res += circularPrime(primes[i]);
        // }
        if(res > 1)
            cout << res << " Circular Primes.\n";
        else if(res)
            cout << res << " Circular Prime.\n";
        else
            cout << "No Circular Primes.\n";


    }
    


}


