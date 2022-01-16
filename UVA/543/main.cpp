#include <bits/stdc++.h>

#define all(a) a.begin(),a.end()
#define fast cin.tie(0),ios::sync_with_stdio(0),cout.tie(0)

typedef long long ll;
typedef unsigned long long ull;

using namespace std;


const int N = 1e6 + 5;
int com[N + 1];
vector<bool>isPrime(N,1);
vector<int>primes;


void sieve(){
    isPrime[0] = isPrime[1] = 0;
    for(int i = 2;1ll * i * i < N;i++){
        if(isPrime[i]){
            for(int j = 2 * i;j<N;j+=i)
                isPrime[j] = 0;
        }
    }
    for(int i = 0;i<N;i++)
        if(isPrime[i])
            primes.push_back(i);

}



int main(void){

    #ifdef Khaled
        freopen("in.txt","r",stdin);
        //freopen("out.txt","w",stdout);
    #endif
    fast;
    sieve();
    int n;
    while(cin >> n , n){
        for(int i = 0;i<primes.size();i++){
            if(isPrime[n - primes[i]]){
                cout << n << " = " << primes[i] << " + " << n - primes[i] << endl;
                break;
            }

        }
    }


}