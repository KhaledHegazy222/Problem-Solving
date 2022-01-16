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


int isDigitPrime(int n){
    int sum = 0;
    string s = to_string(n);
    for(auto it : s)
        sum += it - '0';
    return isPrime[sum] && isPrime[n];
}


int main(void){

    #ifdef Khaled
        freopen("in.txt","r",stdin);
        //freopen("out.txt","w",stdout);
    #endif
    fast;
    sieve();
    for(int i = 1;i<=N;i++)
        com[i] = isDigitPrime(i);
    for(int i = 1;i<=N;i++)
        com[i] += com[i-1];
    int t;
    cin >> t;
    while(t--){
        int l,r;
        cin >> l >> r;
        cout << com[r] - com[max(0,l-1)] << endl;
    }
    
}