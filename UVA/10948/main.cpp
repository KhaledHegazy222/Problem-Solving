#include <bits/stdc++.h>

#define all(a) a.begin(),a.end()
#define fast cin.tie(0),ios::sync_with_stdio(0),cout.tie(0)

typedef long long ll;
typedef unsigned long long ull;

using namespace std;

const int N = 1e6 + 5;
vector<bool>isPrime(N,1);
vector<int>primes;

void sieve(){
    isPrime[0] = isPrime[1] = 0;
    for(ll i = 2;i*i <N;i++){
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
    while(cin >> n,n){
        cout << n << ":\n";
        if(n % 2){
            if(n != 1 && isPrime[n - 2]){
                cout << 2 << "+" << n - 2 << '\n';
            }
            else{
                cout << "NO WAY!\n";
            }
        }
        else{
            if(n == 2){
                cout << "NO WAY!\n";
                continue;
            }
            for(int i = 0;i<primes.size() && n >= primes[i];i++){
                if(isPrime[n - primes[i]]){
                    cout << primes[i] << "+" <<  n - primes[i]<< '\n';
                    break;
                }
            }
        }
    }
    

}